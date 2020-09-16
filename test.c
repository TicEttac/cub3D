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

typedef struct s_struct {

	void	*mlx;
	void	*win;
	void	*img;
	int		*tab;
	long	x;

} t_struct;

int		print_key(int key, t_struct *view)
{
	int i = 0, color = 65536 * 178 + 256 * 102 + 255;
	printf("key pressed=%d\n", key);
		if (key == 126)
			view->x -= 1920;
		if (key == 125)
			view->x += 1920;
		if (key == 123)
			view->x -= 1;
		if (key == 124)
			view->x += 1;
		view->tab[view->x] = color;
		mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	return (0);
}
int		main()
{
	int		bpp = 32;
	int		sl = 1920;
	int		en = 0;
	t_struct view;

	view.x = 0;
	view.mlx = mlx_init();
	view.win = mlx_new_window(view.mlx, 1920, 1080, "cub3D");
	view.img = mlx_new_image(view.mlx, 1920, 1080);
	view.tab = (int*)mlx_get_data_addr(view.img, &bpp, &sl, &en);
	mlx_hook(view.win, 2, 0, &print_key, &view);
	mlx_loop(view.mlx);
	return 0;
}

//2 = key_pressed
//3 = key_release
//4= key_hook
