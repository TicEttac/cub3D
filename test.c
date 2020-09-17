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

typedef struct	s_struct
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*tab;
	long	x;
}				t_struct;

typedef struct	s_tex
{
	int		*tab;
	int		width;
	int		height;
}				t_tex;

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
	int			bpp = 32;
	int			sl = 1920;
	int			en = 0;
	t_struct	view;
	t_tex		tex;

	view.x = 0;
	view.mlx = mlx_init();
	tex.tab = mlx_xpm_file_to_image(view.mlx, "./texture/wall_1.xpm", &tex.width, &tex.height);
	view.win = mlx_new_window(view.mlx, tex.width, tex.width, "wall_1.xpm");
	//view.img = mlx_new_image(view.mlx, tex.width, tex.height);
	//view.tab = (int*)mlx_get_data_addr(view.img, &bpp, &sl, &en);
	mlx_put_image_to_window(view.mlx, view.win, tex.tab, 0, 0);
	printf("width=%d, height=%d\n", tex.width, tex.height);
	//mlx_hook(view.win, 2, 0, &print_key, &view);
	mlx_loop(view.mlx);
	return 0;
}

//2 = key_pressed
//3 = key_release
//4= key_hook
