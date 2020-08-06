/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:25:01 by nisauvig          #+#    #+#             */
/*   Updated: 2020/08/07 01:04:23 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_parse_map(char **conf_file, int size, int index, t_map *file)
{
	int		i;
	int		i_map;

	i = 0;
	i_map = 0;
	while (conf_file[index][i] != '1' && conf_file[index][i] != '0')
	{
		if (index >= size)
		{
			free_dtab(conf_file, size);
			return (error_flag("No map in configuration file.\n"));
		}
		i = conf_file[index][i] == '\0' ? 0 : i + 1;
		i == 0 ? index++ : 0;
	}
	if (!(file->map = malloc(sizeof(t_tile *) * (size - index + 1))))
	{
		free_dtab(conf_file, size);
		return (error_flag("Malloc error.\n"));
	}
	file->mapH = size - index - 2; //"-2" = start at 1 and last line is \0
	while (index < size)
	{
		if (!(file->map[i_map] = malloc(sizeof(t_tile)
						* (ft_strlen(conf_file[index]) + 1))))
		{
			free_dtab(conf_file, size);
			return (error_flag("Malloc error.\n"));
		}
		i = 0;
		while (conf_file[index][i] != '\0')
		{
			if (ft_strchr("NSWE2T ", (int)conf_file[index][i]))
			{
				if (ft_strchr("NSWE", (int)conf_file[index][i]))
				{
					if (file->start[0] != 0)
						return (error_flag("Multiple entry points.\n"));
					file->start[0] = (float)i_map;
					file->start[1] = (float)i;
				}
				file->map[i_map][i].tile = '0';
				file->map[i_map][i].content = conf_file[index][i];
			}
			else if (ft_strchr("10", (int)conf_file[index][i]))
			{
				file->map[i_map][i].tile = conf_file[index][i];
				file->map[i_map][i].content = '0';
			}
			else
			{
				free_dtab(conf_file, size);
				return (error_flag("Erroneous map.\n"));
			}
			i++;
		}
		file->mapW = i - 1 > file->mapW ? i - 1 : file->mapW;
		file->map[i_map][i].tile = '\0';
		file->map[i_map][i].content = '\0';
		index++;
		i_map++;
	}
	free_dtab(conf_file, size - 1);
	if (!(file->map[i_map] = malloc(sizeof(t_tile))))
		return (error_flag("Malloc error.\n"));
	file->map[i_map][0].tile = '\0';
	file->map[i_map][0].content = '\0';
	return (map_checking(file->map, file->start[0], file->start[1]));
}

int		ft_fullfilled(t_map *file)
{
	if (!(file->win[0] && file->win[1]))
		return (0);
	if (!(file->f_color[0] || file->f_color[1] || file->f_color[2]))
		return (0);
	if (!(file->c_color[0] || file->c_color[1] || file->c_color[2]))
		return (0);
	if (file->n_path == 0)
		return (0);
	if (file->so_path == 0)
		return (0);
	if (file->ea_path == 0)
		return (0);
	if (file->we_path == 0)
		return (0);
	if (file->sp_path == 0)
		return (0);
	return (1);
}

void	print_map(t_tile **map)
{
	int		x;
	int		y;

	x = 0;
	while (map[x][0].tile != '\0')
	{
		y = 0;
		while (map[x][y].tile != '\0')
		{
			printf("%c", map[x][y].tile);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("\n");
}

int		map_checking(t_tile **map, int x, int y)
{
	if (x < 0 || y < 0 || map[x][y].tile == '\0' || map[x][0].tile == '\0')
		return (error_flag("Open map.\n"));
	if (map[x][y].tile == '0')
	{
		map[x][y].tile = ' ';
		if (!map_checking(map, x + 1, y) || !map_checking(map, x - 1, y)
		|| !map_checking(map, x, y + 1) || !map_checking(map, x, y - 1))
			return (BAD_OUT);
	}
	return (GOOD_OUT);
}
