/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:50:21 by sosartor          #+#    #+#             */
/*   Updated: 2020/01/25 13:50:23 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

t_bool	check_buf(const char *buf, int size)
{
	int	n;
	int	count;
	int	blocks;

	count = 0;
	blocks = 0;
	n = -1;
	while (++n < 20)
	{
		if (n > 0 && (n + 1) % 5 == 0 && buf[n] != '\n')
			return (FALSE);
		else if (buf[n] == '#')
		{
			blocks++;
			count += n - 1 >= 0 && buf[n - 1] == '#';
			count += n + 1 <= 19 && buf[n + 1] == '#';
			count += n - 5 >= 0 && buf[n - 5] == '#';
			count += n + 5 <= 19 && buf[n + 5] == '#';
		}
		else if ((n == 0 || (n + 1) % 5 != 0) && buf[n] != '.')
			return (FALSE);
	}
	if (size == 21 && buf[20] != '\n')
		return (FALSE);
	return (blocks == 4 && count > 5);
}
