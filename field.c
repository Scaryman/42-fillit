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
	return (res);
}

char	*get_field_from_matrix(char **matrix, int size)
{
	int		n;
	int		i;
	char	*field;
	
	if ((field = ft_strnew(size)) == NULL)
		return (NULL);
	field = ft_memset(field, '.', size);	
	n = 0;
	while (matrix[++n])
		if (matrix[n][0] == '2')
		{
			i = 1;
			while (matrix[n][++i] != '\0')
				if (matrix[n][i] != '0')
					field[i - 2] = matrix[n][i];
		}
	return (field);
}
