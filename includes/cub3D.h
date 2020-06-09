/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:06:20 by nisauvig          #+#    #+#             */
/*   Updated: 2020/06/01 17:37:11 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
#include <X11/Xlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <X11/extensions/XShm.h>
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"

# define GOOD_OUT 1
# define BAD_OUT 0

typedef struct	s_tile
{
	char	tile;
	char	content;
}				t_tile;

typedef struct	s_map
{
	int		win[2];
	int		f_color[3];
	int		c_color[3];
	int		start[2];
	int		n_path;
	int		so_path;
	int		we_path;
	int		ea_path;
	int		sp_path;
	t_tile	**map;
}				t_map;

typedef struct	s_parse
{
	char	*id;
	int		(*func)(char *line, t_map *file, char *id);
}				t_parse;

int		parser(char *str, t_map *file);
int		ft_parse_infos(char **conf_file, int size, t_map *file);
int		ft_parse_map(char **conf_file, int size, int i, t_map *file);
int		map_checking(t_tile **map, int entry_x, int entry_y);
int		error_flag(char *str);
int		ft_fullfilled(t_map *file);
char	*add_path(char *line, char *id);
char	**one_more_line(char **tab, char *to_add, int index);
void	free_dtab(char **dtab, int i);
void	set_struct(t_map *file);

int		add_win(char *line, t_map *file, char *id);
int		add_north(char *line, t_map *file, char *id);
int		add_south(char *line, t_map *file, char *id);
int		add_east(char *line, t_map *file, char *id);
int		add_west(char *line, t_map *file, char *id);
int		add_sprite(char *line, t_map *file, char *id);
int		add_floor(char *line, t_map *file, char *id);
int		add_ceiling(char *line, t_map *file, char *id);

int		mlx_start(t_map *file);

#endif
