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
	int	*tab;
	long	x;
}				t_struct;

typedef struct	s_tex
{
	void	*img;
	void	*tab;
	int		width;
	int		height;
}				t_tex;

int		print_key(int key, t_struct *view)
{
	int i = 0, color = 25432407;
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

void	pass_image(t_tex *tex, t_struct *view)
{
	int			x = 0;
	int			y = 0;
	int			bpp = 32;
	int			sl = tex->width;
	int			en = 0;

	//printf("width=%d, height=%d\n", tex->width, tex->height);
	while (x < tex->width && y < tex->height)
	{
		view->tab[x + (y * tex->width)] = ((int*)tex->tab)[x + (y * tex->width)];
		printf("tab[%d][%d]=%d\n", x, y, ((int*)view->tab)[x + (y * tex->width)]);
		x++;
		if (x == tex->width)
		{
			printf("reset\n");
			x = 0;
			y++;
		}
	}
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
}

int		main(int ac, char **av)
{
	int			sl;
	int			bpp = 32;
	int			en = 0;
	t_struct	view;
	t_tex		tex;

	if (ac == 1)
	{
		printf("no arguments.\n");
		return (0);
	}
	view.x = 0;
	view.mlx = mlx_init();
	tex.img = mlx_xpm_file_to_image(view.mlx, av[1], &tex.width, &tex.height);
	view.win = mlx_new_window(view.mlx, tex.width, tex.width, "watch xpm");
	view.img = mlx_new_image(view.mlx, tex.width, tex.height);
	view.tab = (int *)mlx_get_data_addr(view.img, &bpp, &sl, &en);
	tex.tab = (unsigned int*)mlx_get_data_addr(tex.img, &bpp, &sl, &en);
	pass_image(&tex, &view);
	printf("tab after=%d\n", view.tab[63 + 63 * tex.width]);
//	mlx_hook(view.win, 2, 0, &print_key, &view);
	mlx_loop(view.mlx);
	return 0;
}

//2 = key_pressed
//3 = key_release
//4= key_hook
