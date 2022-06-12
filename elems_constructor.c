#include "cub3d.h"

t_elems	*elems_constructor(int ac, char **av)
{
	t_elems	*elems;

	(void)ac;
	elems = malloc(sizeof(t_elems));
	if (!elems)
		wr_error(2, "Faild to allocate memory\n");
	elems->map = get_map(av[1]);
	return (elems);
}