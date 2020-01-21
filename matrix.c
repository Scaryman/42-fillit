#include "fillit.h"

int		get_min_field_size(t_tet *head)
{
	int		n;
	int		i;
	t_tet	*tmp;
	int		res;

	n = 0;
	res = 1;
	tmp = head;
	while (tmp)
	{
		i = -1;
		while (++i < 4)
			res = get_max(res, get_max(tmp->x[i], tmp->y[i]) + 1);
		tmp = tmp->next;
		n++;
	}
	while (res * res < n * 4)
		res++;
}

char	*join_variant(char *lm, char *variant)
{
	char *tmp;

	tmp = lm;
	if ((lm = ft_strjoin(lm, variant)) == NULL)
		return (NULL);
	ft_strdel(&tmp);
	return (lm);
}

t_bool	fill_variants(char **lm, char **field, t_tet *tet, int fs)
{
	int	n;
	int	shift;
	int	pos;

	shift = -1;
	while (++shift < fs * fs - 4)
	{
		*field = ft_memset(field, '0', fs * fs);
		n = -1;
		while (++n < 4)
		{
			pos = tet->y[n] * fs + tet->x[n] + shift;
			if (pos % fs != 0 && pos < fs * fs)
				*field[pos] = '1';
			else
				break;
		}
		if (n == 4)
			if ((*lm == join_variant(*lm, field)) == NULL)
				return (FALSE);
	}
	return (TRUE);
}

char	**line_to_matrix(char **line, int fs)
{
	char 	**matrix;
	int		height;
	int		n;

	height = ft_strlen(*line) / (fs * fs) + 1;
	if ((matrix = ft_memalloc(sizeof(char *) * (height + 2))) == NULL)
	{
		ft_strdel(line);
		return (NULL);
	}
	n = -1;
	while (++n < height)
	{
		if ((matrix[n] = ft_strnew((fs * fs) + 1)) == NULL)
		{
			ft_strdel(line);
			return (NULL);
		}
		matrix[n] = ft_memset(matrix[n], '0', fs * fs);
		if (n > 0)
			ft_memcpy(matrix[n][1], line(n * fs * fs), fs * fs);
	}
	ft_strdel(line);
	return (matrix);
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
		return (NULL);
	while (cur_tet)
	{
		if (fill_variants(&line, &tmp, cur_tet, field_size) == FALSE)
			break;
		cur_tet = cur_tet->next;
	}
	ft_strdel(&tmp);
	if (line)
	{
		ft_strdel(&line);
		return (line_to_matrix(&line));
	}
	else
		return (NULL);
}
