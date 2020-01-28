/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:04:38 by sosartor          #+#    #+#             */
/*   Updated: 2020/01/28 19:18:51 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_arrs(char *arr, char **arr2d)
{
	int n;

	if (arr != NULL)
		ft_memdel((void**)&arr);
	if (arr2d != NULL)
	{
		n = -1;
		while (arr2d[++n])
		{
			free(arr2d[n]);
			arr2d[n] = NULL;
		}
		free(arr2d);
		arr2d = NULL;
	}
}
