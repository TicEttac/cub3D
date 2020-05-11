#include "includes/cub3D.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_map file;
	int index = 0;
	int i;

	(void)ac;
	if (!parser(av[1], &file))
		return (0);
	while (file.map[index][0].tile != '\0'){
		i = 0;
		while (file.map[index][i].tile != '\0'){
			printf("%c", file.map[index][i].tile);
			i++;
		}
		printf("\n");
		index++;
	}
	i = 0;
	while (index >= 0){
		free(file.map[index]);
		index--;
	}
	free(file.map);
	free(file.n_path);
	free(file.so_path);
	free(file.ea_path);
	free(file.we_path);
	free(file.sp_path);
	return (0);
}
