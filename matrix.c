/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:47:49 by sosartor          #+#    #+#             */
/*   Updated: 2020/01/25 13:47:51 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**complete_matrix(char **matrix)
{
	int	n;
	int	i;

	n = 1;
	while (matrix[0][++n] != '\0')
		matrix[0][n] = '1';
	n = 0;
	while (matrix[++n])
	{
		matrix[n][0] = '1';
		i = 2;
		while (matrix[n][i] == '0')
			i++;
		matrix[n][1] = matrix[n][i];
	}
	return (matrix);
}

char	*join_variant(char *lm, char *variant)
{
	char *tmp;

	tmp = lm;
	if ((lm = ft_strjoin(lm, variant)) == NULL)
		return (NULL);
	ft_memdel((void**)&tmp);
	return (lm);
}

t_bool	fill_variants(char **lm, char **field, t_tet *tet, int fs)
{
	int	n;
	int	shift;
	int	pos;

	shift = -1;
	while (++shift <= fs * fs - 4)
	{
		*field = ft_memset(*field, '0', fs * fs);
		n = -1;
		while (++n < 4)
		{
			pos = tet->y[n] * fs + tet->x[n] + shift;
			if (pos < fs * fs && (pos == 0 || (pos % fs == 0
				&& (n == 0 || tet->y[n - 1] < tet->y[n]))
				|| pos % fs != 0))
				(*field)[pos] = tet->c;
			else
				break ;
		}
		if (n == 4)
			if ((*lm = join_variant(*lm, *field)) == NULL)
				return (FALSE);
	}
	return (TRUE);
}

char	**line_to_matrix(char **line, int fs)
{
	char	**matrix;
	int		height;
	int		n;

	height = (int)ft_strlen(*line) / (fs * fs) + 1;
	if ((matrix = (char **)malloc(sizeof(char *) * (height + 1))) == NULL)
	{
		free_arrs(*line, NULL);
		return (NULL);
	}
	n = -1;
	while (++n < height)
	{
		if ((matrix[n] = ft_strnew((fs * fs) + 2)) == NULL)
		{
			free_arrs(*line, matrix);
			return (NULL);
		}
		matrix[n] = ft_memset(matrix[n], '0', fs * fs + 2);
		if (n > 0)
			ft_memcpy(&matrix[n][2], &(*line)[(n - 1) * fs * fs], fs * fs);
	}
	matrix[n] = NULL;
	ft_memdel((void **)line);
	return (complete_matrix(matrix));
}

char	**get_matrix(int field_size, t_tet *tets)
{
	char	*line;
	char	*tmp;
	t_tet	*cur_tet;

	cur_tet = tets;
	if ((tmp = ft_strnew(field_size * field_size)) == NULL)
		return (NULL);
	if ((line = ft_strnew(0)) == NULL)
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	while (cur_tet)
	{
		if (fill_variants(&line, &tmp, cur_tet, field_size) == FALSE)
			break ;
		cur_tet = cur_tet->next;
	}
	ft_strdel(&tmp);
	if (line)
	{
		return (line_to_matrix(&line, field_size));
	}
	else
		return (NULL);
}
