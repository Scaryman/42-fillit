/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:47:39 by sosartor          #+#    #+#             */
/*   Updated: 2020/01/25 13:47:42 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*create_tets(char *filename)
{
	int		fd;
	t_tet	*tets;
	t_tet	*new;
	int		res;
	char	c;

	tets = NULL;
	new = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	c = 'A';
	res = 0;
	while ((res = get_tet(fd, &new, res, c++)) > 0)
		if (lstadd(&tets, new) == FALSE)
		{
			res = -1;
			break ;
		}
	close(fd);
	if (res == -1 || res == 21)
		free_tets(&tets);
	return (tets);
}

t_tet	*create_tet(const char *buf, int size, char c)
{
	t_tet	*tet;
	int		n;
	int		i;

	if ((tet = (t_tet *)malloc(sizeof(t_tet))) != NULL)
	{
		i = 0;
		n = -1;
		while (++n < size)
		{
			if (buf[n] == '#')
			{
				tet->x[i] = n % 5;
				tet->y[i] = n / 5;
				tet->c = c;
				i++;
			}
		}
		tet->next = NULL;
	}
	shift_tet(&tet);
	return (tet);
}

int		get_tet(int fd, t_tet **new, int prev_res, char c)
{
	char	*buf;
	int		size;

	if ((buf = ft_strnew(21)) == NULL)
		return (-1);
	if ((size = read(fd, buf, 21)) >= 20)
	{
		if (check_buf(buf, size) == TRUE)
		{
			if ((*new = create_tet(buf, size, c)) == NULL)
				size = -1;
		}
		else
			size = -1;
	}
	else if (size > 0 || prev_res == 21)
		size = -1;
	ft_strdel(&buf);
	return (size);
}

void	free_tets(t_tet **head)
{
	t_tet	*tmp;
	t_tet	*next;

	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		ft_memdel((void**)&tmp);
		tmp = next;
	}
	*head = NULL;
}

void	shift_tet(t_tet **tet)
{
	t_tet	*tmp;
	int		i;
	int		min_x;
	int		min_y;

	tmp = *tet;
	i = -1;
	min_x = 4;
	min_y = 4;
	while (++i < 4)
	{
		min_x = get_min(min_x, tmp->x[i]);
		min_y = get_min(min_y, tmp->y[i]);
	}
	while (--i >= 0)
	{
		tmp->x[i] = tmp->x[i] - min_x;
		tmp->y[i] = tmp->y[i] - min_y;
	}
}
