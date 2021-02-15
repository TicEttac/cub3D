#include "../includes/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd, fd2, gnl, gnl2;
	char *line = NULL, *line2 = NULL;

	if ((fd2 = open(av[2], O_RDONLY)) == -1)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	while ((gnl = get_next_line(fd, &line)) > 0 || (gnl2 = get_next_line(fd2, &line2) > 0))
	{
		printf("-------------<%s>\n", line2);
		printf("<%s>\n", line);
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		if (line2 != NULL)
		{
			free(line2);
			line2 = NULL;
		}
	}
	close(fd);
	close(fd2);
	return (0);
}
