/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:06:20 by nisauvig          #+#    #+#             */
/*   Updated: 2020/08/04 16:31:04 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include <sys/ipc.h>
# include <sys/shm.h>
# include "get_next_line.h"
# include "mlx.h"

# define GOOD_OUT 1
# define BAD_OUT 0

# define FOV (M_PI / 3)

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define BLACK 0x000000

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53
# define LEFT_KEY 123
# define RIGHT_KEY 124

typedef struct	s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct	s_tile
{
	char	tile;
	char	content;
}				t_tile;

typedef struct	s_img
{
	void	*img;
	int		*tab;
	int		sl;
}				t_img;

typedef struct	s_tex
{
	int		*tex;
	int		*tab;
	t_point	cnt;
	int		width;
	int		height;
}				t_tex;

typedef struct	s_map
{
	int		win[2];
	int		f_color[3];
	int		c_color[3];
	float	start[2];
	t_tex	n_path;
	t_tex	so_path;
	t_tex	we_path;
	t_tex	ea_path;
	t_tex	sp_path;
	int		mapH;
	int		mapW;
	t_tile	**map;
}				t_map;

typedef struct	s_char
{
	void	*mlx;
	void	*win;
	float	x;
	float	y;
	float	dir;
	t_map	*file;
	t_img	image;
}				t_char;

typedef struct	s_parse
{
	char	*id;
	int		(*func)(char *line, t_map *file, char *id);
}				t_parse;

/*------------------------------__PROTOTYPES__------------------------------*/
/*---------------------------------< EXIT >---------------------------------*/

int		error_flag(char *str);
int		clean_exit(t_char *player);

/*--------------------------------< PARSING >-------------------------------*/

int		parser(char *str, t_map *file);
int		ft_parse_infos(char **conf_file, int size, t_map *file);
int		ft_parse_map(char **conf_file, int size, int i, t_map *file);
int		map_checking(t_tile **map, int entry_x, int entry_y);
int		ft_fullfilled(t_map *file);
char	*add_path(char *line, char *id);
char	**one_more_line(char **tab, char *to_add, int index);
void	free_dtab(char **dtab, int i);
void	set_struct(t_map *file);

/*----------------------------< COLOR AND TEXTURES >------------------------*/

int		add_win(char *line, t_map *file, char *id);
int		add_north(char *line, t_map *file, char *id);
int		add_south(char *line, t_map *file, char *id);
int		add_east(char *line, t_map *file, char *id);
int		add_west(char *line, t_map *file, char *id);
int		add_sprite(char *line, t_map *file, char *id);
int		add_floor(char *line, t_map *file, char *id);
int		add_ceiling(char *line, t_map *file, char *id);
int		load_north(t_char *player);
int		load_south(t_char *player);
int		load_east(t_char *player);
int		load_west(t_char *player);
int		load_sprite(t_char *player);

/*---------------------------------< MLX >----------------------------------*/

int		mlx_start(t_char *player);
int		rendering(t_char *player);
t_point	wall_dist(float delta_ray, t_char *player);
int		apply_ray(t_point cnt, t_char *player, float ray, int seg);
int		column_trace(t_char *player, float hyp, int seg, t_tex tex);
void	init_image(t_char *player);
int		load_texture(t_char *player);

/*---------------------------------< HOOKS >--------------------------------*/

int		mlx_hooks(t_char *player);
int		key_hook(int key, t_char *player);


#endif
