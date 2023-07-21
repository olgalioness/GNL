#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("file", O_RDONLY);
	// get_next_line(fd, &line);
	// printf("line = %s\n", line);
	// free(line);
	// get_next_line(fd, &line);
	// printf("line = %s\n", line);
	// free(line);
	// get_next_line(fd, &line);
	// printf("line = %s\n", line);
	// free(line);
	// get_next_line(fd, &line);
	// printf("line = %s\n", line);
	// free(line);
	while ((i = get_next_line(0, &line)) > 0)
	{
		printf("fd = %d i = %d line = %s\n", fd, i, line);
		free(line);
		line = NULL;
	}
	if (i == -1)
	{
		printf("ASHIBKA\n");
		return(0);
	}
	printf("fd = %d i = %d line = %s\n", fd, i, line);
	free(line);
	line = NULL;
	close(fd);
	return (0);
}
