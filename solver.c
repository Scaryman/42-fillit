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

int		get_solution(int field_size, t_tet *tets)
{
	char	**matrix;
	int	solved;

	if ((matrix = get_matrix(field_size, tets)) == NULL)
		return (-1);
	solved = solve(matrix, tets, 1);
	free_arrs(NULL, matrix);
	return (solved);
}

int	solve(char **matrix, t_tet *cur_tet, int n)
{
	int solved;
	
	if (cur_tet == NULL)
		return(print_solution(matrix));
	while (matrix[n])
	{
		if (matrix[n][0] == '1' && matrix[n][1] == cur_tet->c)
		{
			matrix = set_covering(matrix, n);

//			tmp_print_matrix(matrix);
//			ft_putchar('\n');

			if ((solved = solve(matrix, cur_tet->next, n + 1)) != 0)
				return (solved);
			else
				matrix = unset_covering(matrix, n);

//			tmp_print_matrix(matrix);
//			ft_putchar('\n');
		}
		n++;
	}
	return (0);
}

char	**set_covering(char **matrix, int row)
{
	int n;
	int i;
	
	matrix[row][0] = '2';
	n = 1;
	while (matrix[row][++n])
	{
		if (matrix[row][n] != '0')
		{
			matrix[0][n] = '0';
			i = 0;
			while (matrix[++i])
				if (matrix[i][n] != '0' && matrix[i][0] == '1')
					matrix[i][0] = matrix[row][1];
		}
	}
	return (matrix);
}

char	**unset_covering(char **matrix, int row)
{
	int n;
	int i;
	
	matrix[row][0] = '1';
	n = 1;
	while (matrix[row][++n])
	{
		if (matrix[row][n] != '0')
		{
			matrix[0][n] = '1';
			i = 0;
			while (matrix[++i])
				if (matrix[i][n] != '0' && matrix[i][0] == matrix[row][1])
					matrix[i][0] = '1';
		}
	}
	return (matrix);
}
