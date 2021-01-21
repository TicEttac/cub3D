#include "../includes/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd, gnl;
	char *line;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	while ((gnl = get_next_line(fd, &line)) > 0)
		printf("<%s>\n", line);
	return (0);
}
