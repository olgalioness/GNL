#include <stdio.h>
#include <fcntl.h>
#include "./get_next_line.h"

int main(void){
	int fd;
	char *line;

	fd = open("./get_next_line_utils.c", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("%s\n \n ->", line);
	}
	return 0;
}
