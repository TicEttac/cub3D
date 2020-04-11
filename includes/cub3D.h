/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:06:20 by nisauvig          #+#    #+#             */
/*   Updated: 2020/03/12 17:46:41 by nisauvig         ###   ########.fr       */
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
# include "get_next_line.h"

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
	char	*n_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*sp_path;
	t_tile	**map;
}				t_map;

typedef struct	s_parse
{
	char	*id;
	int		(*func)(char *line, t_map *file, char *id);
}				t_parse;

int		parser(char *str, t_map *file);
int		ft_parse_infos(char **conf_file, int size, t_map *file);
int		ft_parse_map(char **conf_file, int size, t_map *file);
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

#endif
