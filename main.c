#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tet	*tets;
	int		field_size;

	if (argc != 2)
		ft_putendl("usage: fillit <path_to_input_file>");
	else
	{
		if ((tets = create_tets(argv[1])) == NULL)
			ft_putendl("Error");
		else
		{
			ft_putendl("good");
			field_size = get_min_field_size(tets);
			while ((res = solve(field_size++, &tets)) != 1)
				if (res == -1)
				{
					ft_putendl("Error");
					break ;
				}
			free_tets(&tets);
		}
	}
	return (0);
}
