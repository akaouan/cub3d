#include "cub3d.h"

void wr_error(int fd, char *err_msg)
{
	ft_putstr_fd("ERROR: ", fd);
	ft_putstr_fd(err_msg, fd);
	exit(EXIT_FAILURE);
}