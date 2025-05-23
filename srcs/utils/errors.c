#include "test.h"

void	cub_handle_fatal(t_data *data, char *custom_msg)
{
	if (!custom_msg)
		perror("cub3d:");
	else
		ft_printfd(2, "%s%s%s\n", P_YELLOW, custom_msg, P_NOC);
	cub_clean_data(data);
	exit(EXIT_FAILURE);
}

void	cub_handle_fatal_parse(t_data *data, int fd, char *line, char *msg)
{
	free(line);
	close(fd);
	cub_handle_fatal(data, msg);
}
