#include "cub3d.h"

int main(int ac, char **av)
{
	t_elems *elems;
	
	elems = elems_constructor(ac, av);
	for(int i = 0; elems->map[i]; i++)
		printf("%s\n", elems->map[i]);
	// free(elems);
	system("leaks cub3d");
	return (0);
}