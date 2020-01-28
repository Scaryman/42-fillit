/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:21:03 by sosartor          #+#    #+#             */
/*   Updated: 2020/01/28 20:21:05 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	print_solution(char **matrix)
{
	int		n;
	int		size;
	char	*field;

	size = ft_sqrt(ft_strlen(&matrix[0][2]));
	if (size == -1
		|| (field = get_field_from_matrix(matrix, size * size)) == NULL)
		return (-1);
	n = -1;
	while (field[++n] != '\0')
	{
		ft_putchar(field[n]);
		if (n != 0 && (n + 1) % size == 0)
			ft_putchar('\n');
	}
	ft_memdel((void**)&field);
	return (1);
}
