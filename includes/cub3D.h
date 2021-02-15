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
# include <stdbool.h>
# include <math.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>

# define GOOD_OUT 1
# define BAD_OUT 0

# define FOV (M_PI / 3)
# define SPEED 0.3

# define RED 0x0f00
# define GREEN 0x00f0
# define BLUE 0x000f

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

/*		macOS keys
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53
# define LEFT_KEY 123
# define RIGHT_KEY 124
*/
typedef struct	s_point
{
	float	x;
	float	y;
}		t_point;

typedef	struct	s_sprite
{
	t_point	pos;
	int	line;
}		t_sprite;

typedef struct	s_tile
{
	char	tile;
	char	content;
}		t_tile;

typedef struct	s_img
{
	void	*img;
	int	*tab;
	int	sl;
}		t_img;

typedef struct	s_tex
{
	int	*tex;
	int	*tab;
	t_point	cnt;
	int	width;
	int	height;
}		t_tex;

typedef struct	s_map
{
	int	win[2];
	int	f_color[3];
	int	c_color[3];
	float	start[2];
	t_tex	n_path;
	t_tex	so_path;
	t_tex	we_path;
	t_tex	ea_path;
	t_tex	sp_path;
	int	mapH;
	int	mapW;
	t_tile	**map;
}		t_map;

typedef struct  s_keys
{
	bool	front;
	bool	back;
	bool	wkleft;
	bool	wkright;
	bool	left;
	bool	right;
}		t_keys;

typedef struct	s_char
{
	bool	save;
	bool	sprite;
	t_keys	keys;
	void	*mlx;
	void	*win;
	float	x;
	float	y;
	float	dir;
	t_map	*file;
	t_img	image;
}		t_char;

typedef struct	s_parse
{
	char	*id;
	int	(*func)(char *line, t_map *file, char *id);
}		t_parse;

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
char		*add_path(char *line, char *id);
char		**one_more_line(char **tab, char *to_add, int index);
void		free_dtab(char **dtab, int i);
void		set_struct(t_map *file);

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
void		init_image(t_char *player);
int		load_texture(t_char *player);

/*---------------------------------< HOOKS >--------------------------------*/

int		mlx_hooks(t_char *player);
int		key_release(int key, t_char *player);
int		key_hook(int key, t_char *player);

/*---------------------------------< RAY >---------------------------------*/

int		test_pos(t_point next, t_tile **map);
t_point		key_mod(t_char *player);
t_point		wall_dist(float delta_ray, t_char *player);
t_point		wall_dist_no_sprite(float delta_ray, t_char *player);
t_point		wall_diff(float delta, t_point player);
t_point		contact(t_point player);
t_point		hypotenuse(t_point diff, float delta);
int		apply_ray(t_point cnt, t_char *player, float ray, int seg);
int		column_trace(t_char *player, float hyp, int seg, t_tex tex);
t_point 	check_x(float delta, t_point addx);
t_point 	check_y(float delta, t_point addy);
t_point		sprite_dist(float ray, t_point cnt, t_tile **map, t_point player);
int     	colum_fill(t_char *player, float wall, long seg, t_tex tex);

/*-------------------------------< SPRITE >--------------------------------*/

void		sprite(t_char *player, t_point cont, int seg, float ray);
float		test_fuck(float ray, t_point cnt, t_point center, float dist);
int		one_step(float delta, t_point cnt, t_point *cont, t_point *diff, t_point *c);
int		sprite_fill(t_char *player, float wall, long seg, t_tex tex);

/*---------------------------------< BMP >---------------------------------*/

void		img_bmp(t_char *player);

#endif
