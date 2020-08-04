#include "includes/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <math.h>
int main()
{
	void	*mlx;
	void	*win;
	int		x;

	x = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "cub3D");
	while (x < 1000){
		mlx_pixel_put(mlx, win, x, 120, 14753280);
		x++;
	}
	mlx_loop(mlx);
	return 0;
}
