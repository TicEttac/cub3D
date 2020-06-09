/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:24:44 by nisauvig          #+#    #+#             */
/*   Updated: 2020/05/24 19:24:48 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		add_north(char *line, t_map *file, char *id)
{
	file->n_path = open(add_path(line, id), O_RDONLY);
	if (file->n_path == -1)
		return (error_flag("North path open error.\n"));
	return (GOOD_OUT);
}

int		add_south(char *line, t_map *file, char *id)
{
	file->so_path = open(add_path(line, id), O_RDONLY);
	if (file->so_path == -1)
		return (error_flag("South path open error.\n"));
	return (GOOD_OUT);
}

int		add_east(char *line, t_map *file, char *id)
{
	file->ea_path = open(add_path(line, id), O_RDONLY);
	if (file->ea_path == -1)
		return (error_flag("East path open error.\n"));
	return (GOOD_OUT);
}

int		add_west(char *line, t_map *file, char *id)
{
	file->we_path = open(add_path(line, id), O_RDONLY);
	if (file->we_path == -1)
		return (error_flag("West path open error.\n"));
	return (GOOD_OUT);
}

int		add_sprite(char *line, t_map *file, char *id)
{
	file->sp_path = open(add_path(line, id), O_RDONLY);
	if (file->sp_path == -1)
		return (error_flag("Sprite path open error.\n"));
	return (GOOD_OUT);
}
