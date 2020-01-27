/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:51:43 by sosartor          #+#    #+#             */
/*   Updated: 2020/01/25 13:51:47 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define FALSE 0
# define TRUE 1

typedef struct		s_tet
{
	int				x[4];
	int				y[4];
	char			c;
	struct s_tet	*next;
}					t_tet;
typedef int			t_bool;
t_tet				*create_tets(char *filename);
t_tet				*create_tet(const char *buf, int size, char c);
int					get_tet(int fd, t_tet **new, char c);
void				free_tets(t_tet **head);
void				lstadd(t_tet **head, t_tet *tet);
int					get_max(int a, int b);
t_bool				check_buf(const char *buf, int size);
int					get_min_field_size(t_tet *head);
char				**get_matrix(int field_size, t_tet *tets);
int					solve(int field_size, t_tet **tets);
int					get_min(int a, int b);
void				shift_tet(t_tet **tet);
void				free_arrs(char *arr, char **arr2d);
#endif
