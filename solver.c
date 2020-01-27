/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:48:01 by sosartor          #+#    #+#             */
/*   Updated: 2020/01/25 13:48:03 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tmp_print_matrix(char **matrix)
{
	int n;
	int i;

	n = -1;
	while (matrix[++n])
	{
		i = -1;
		while (matrix[n][++i] != '\0')
			ft_putchar(matrix[n][i]);
		ft_putchar('\n');
	}
}

int		solve(int field_size, t_tet **tets)
{
	char	**matrix;

	if ((matrix = get_matrix(field_size, *tets)) == NULL)
		return (-1);
	tmp_print_matrix(matrix);
	free_arrs(NULL, matrix);
	return (1);
}
