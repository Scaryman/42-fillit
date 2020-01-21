#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tet	*tets;

	if (argc != 2)
		ft_putendl("usage: fillit path_to_input_file");
	else
	{
		if ((tets = create_tets(argv[1])) == NULL)
			ft_putendl("Error");
		else
		{
			ft_putendl("good");
			free_tets(&tets);
		}
	}
	return (0);
}
