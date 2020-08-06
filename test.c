#include "includes/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <math.h>
#include <stdio.h>

int		print_key()
{
	printf("gut\n");
	return (0);
}
int		main()
{
	void	*mlx;
	void	*win;
	int		x;

	x = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "cub3D");
	mlx_key_hook(win, &print_key, NULL);
	mlx_loop(mlx);
	return 0;
}
