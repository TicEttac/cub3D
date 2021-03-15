/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <nisauvig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:25:01 by nisauvig          #+#    #+#             */
/*   Updated: 2021/03/15 15:04:10 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_parse(int size, char **conf_file, int *index)
{
	int	i;

	i = 0;
	while (conf_file[*index][i] != '1' && conf_file[*index][i] != '0')
	{
		if (*index >= size)
			return (get_tight("No map in config file.\n", conf_file, *index));
		if (conf_file[*index][i] == '\0')
		{
			i = 0;
			*index += 1;
		}
		else
			i++;
	}
	return (i);
}

int	set_spawn(t_map *file, int i_map, int i)
{
	if (file->start[0] != 0)
		return (error_flag("Multiple entry points.\n"));
	file->start[0] = (float)i_map;
	file->start[1] = (float)i;
	return (GOOD_OUT);
}

int	translate_map(int index, int i_map, char **conf_file, t_map *file)
{
	int	i;

	i = -1;
	while (conf_file[index][++i] != '\0')
		if (ft_strchr("NSWET ", (int)conf_file[index][i]))
		{
			if (ft_strchr("NSWE", (int)conf_file[index][i])
						&& !set_spawn(file, i_map, i))
				return (get_tight("Multiple entry point.\n", conf_file, index));
			file->map[i_map][i].tile = '0';
			file->map[i_map][i].content = conf_file[index][i];
		}
		else if (ft_strchr("210", (int)conf_file[index][i]))
		{
			file->map[i_map][i].tile = conf_file[index][i];
			file->map[i_map][i].content = '0';
		}
		else
			return (get_tight("Erroneous map.\n", conf_file, index));
	if (i > 0)
		return (i);
	else
		return (GOOD_OUT);
}

int	ft_parse_map(char **conf_file, int size, int index, t_map *file)
{
	int	i;
	int	i_map;

	i_map = 0;
	if ((i = map_parse(size, conf_file, &index)) == BAD_OUT)
		return (BAD_OUT);
	if (!(file->map = malloc(sizeof(t_tile *) * (size - index + 1))))
		return (get_tight("Malloc error.\n", conf_file, size));
	file->mapH = size - index - 2;
	while (index < size)
		if (!(file->map[i_map] = malloc(sizeof(t_tile)
						* (ft_strlen(conf_file[index]) + 1))))
			return (get_tight("Malloc error.\n", conf_file, index));
		else if (!straw_man(&index, &i_map, conf_file, file))
			return (BAD_OUT);
	free_dtab(conf_file, size - 1);
	if (!(file->map[i_map] = malloc(sizeof(t_tile))))
		return (error_flag("Malloc error.\n"));
	file->map[i_map][0].tile = '\0';
	file->map[i_map][0].content = '\0';
	return (map_checking(file->map, file->start[0], file->start[1]));
}
