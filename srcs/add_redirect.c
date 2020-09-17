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

int		add_south(char *line, t_map *file, char *id)
{
	int	i;

	i = open(add_path(line, id), O_RDONLY);
	if (i == -1)
		return (error_flag("South path open error.\n"));
	if (!(file->so_path.tex = (void *)ft_strdup(add_path(line, id))))
		return (error_flag("South path malloc error.\n"));
	return (GOOD_OUT);
}

int		add_north(char *line, t_map *file, char *id)
{
	int	i;

	i = open(add_path(line, id), O_RDONLY);
	if (i == -1)
		return (error_flag("South path open error.\n"));
	if (!(file->n_path.tex = (void *)ft_strdup(add_path(line, id))))
		return (error_flag("South path malloc error.\n"));
	return (GOOD_OUT);
}

int		add_east(char *line, t_map *file, char *id)
{
	int	i;

	i = open(add_path(line, id), O_RDONLY);
	if (i == -1)
		return (error_flag("South path open error.\n"));
	if (!(file->ea_path.tex = (void *)ft_strdup(add_path(line, id))))
		return (error_flag("South path malloc error.\n"));
	return (GOOD_OUT);
}

int		add_west(char *line, t_map *file, char *id)
{
	int	i;

	i = open(add_path(line, id), O_RDONLY);
	if (i == -1)
		return (error_flag("South path open error.\n"));
	if (!(file->we_path.tex = (void *)ft_strdup(add_path(line, id))))
		return (error_flag("South path malloc error.\n"));
	return (GOOD_OUT);
}

int		add_sprite(char *line, t_map *file, char *id)
{
	int	i;

	i = open(add_path(line, id), O_RDONLY);
	if (i == -1)
		return (error_flag("South path open error.\n"));
	if (!(file->sp_path.tex = (void *)ft_strdup(add_path(line, id))))
		return (error_flag("South path malloc error.\n"));
	return (GOOD_OUT);
}
