#include "cub3d.h"

int	map_lines(int *map_fd, char *map_path)
{
	int	size;
	char *buffer;

	size = 0;
	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(*map_fd);
		free(buffer);
		if (!buffer)
			break ;
		size++;
	}
	close(*map_fd);
	*map_fd = open(map_path, O_RDONLY);
	return (size);
}

char	**read_map(int *map_fd, char *map_path)
{
	int		i;
	int		size;
	char	**map;

	i = 0;
	size = map_lines(map_fd, map_path);
	map = malloc((sizeof(char *) * size) + 1);
	if (!map)
		wr_error(2, "Faild to allocate memory\n");
	while (i < size)
		map[i++] = get_next_line(*map_fd);
	map[i] = NULL;
	return (map);
}

char	**get_map(char *map_path)
{
	char	**map;
	int		map_fd;

	map_fd = open(map_path, O_RDONLY);
	map = NULL;
	if (map_fd == -1)
		wr_error(2, "Couldn't found the map file\n");
	map = read_map(&map_fd, map_path);
	return (map);
}