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

int	solve(int field_size, t_tet **tets)
{
	char	**matrix;

	if ((matrix = get_matrix(field_size, *tets)) == NULL)
		return (-1);
	return (0);
}
