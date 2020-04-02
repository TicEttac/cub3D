#include "includes/cub3D.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_map file;

	(void)ac;
	parser(av[1], &file);
	printf("win x[%d] y[%d]\n", file.win[0], file.win[1]);
	printf("north path [%s]\n", file.n_path);
	printf("south path [%s]\n", file.so_path);
	printf("east path [%s]\n", file.ea_path);
	printf("west path [%s]\n", file.we_path);
	printf("sprite path [%s]\n", file.sp_path);
	printf("floor color R[%d] G[%d] B[%d]\n", file.f_color[0], file.f_color[1], file.f_color[2]);
	printf("ceiling color R[%d] G[%d] B[%d]\n", file.c_color[0], file.c_color[1], file.c_color[2]);
	free(file.n_path);
	free(file.so_path);
	free(file.ea_path);
	free(file.we_path);
	free(file.sp_path);
	return (0);
}
