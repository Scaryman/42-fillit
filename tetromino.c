#include "fillit.h"

t_tet	*create_tets(char *filename)
{
	int		fd;
	t_tet	*tets;
	t_tet	*new;
	int		res;

	tets = NULL;
	new = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while ((res = get_tet(fd, &new)) > 0)
	{
		lstadd(&tets, new);
	}
	close(fd);
	if (res == -1)
		free_tets(&tets);
	return (tets);
}

t_tet	*create_tet(const char *buf, int size)
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
				i++;
			}
		}
		tet->next = NULL;
	}
	return (tet);
}

int		get_tet(int fd, t_tet **new)
{
	char	*buf;
	int		n;
	int		size;

	if ((buf = ft_strnew(21)) == NULL)
		return (-1);
	n = -1;
	if ((size = read(fd, buf, 21)) >= 20)
	{
		if (check_buf(buf, size) == TRUE)
		{
			if ((*new = create_tet(buf, size)) == NULL)
				size = -1;
		}
		else
			size = -1;
	}
	ft_strdel(&buf);
	if (size == 0 || size == -1)
		return (size);
	return (1);
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

void	lstadd(t_tet **head, t_tet *tet)
{
	t_tet	*tmp;

	tmp = *head;
	if (!tmp)
		*head = tet;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tet;
	}
}

