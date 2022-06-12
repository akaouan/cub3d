#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct n_elems{
	char **map;
}	t_elems;

t_elems	*elems_constructor(int ac, char **av);
void	wr_error(int fd, char *err_msg);
char	**get_map(char *map_path);
#endif