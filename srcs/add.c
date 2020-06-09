/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:24:24 by nisauvig          #+#    #+#             */
/*   Updated: 2020/05/24 19:24:42 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		add_win(char *line, t_map *file, char *id)
{
	int		i;
	char	swich;

	(void)id;
	i = 0;
	swich = 0;
	while (ft_strchr(" \tR", line[i]))
		i++;
	while (line[i] && swich <= 1)
	{
		if ((line[i] > '9' || line[i] < '0') && !ft_strchr(" \t", line[i]))
			return (error_flag("Window size error.\n"));
		if (ft_strchr(" \t\0", line[i]))
		{
			swich++;
			while (ft_strchr(" \t", line[i + 1]))
				i++;
		}
		else
			file->win[swich] = file->win[swich] * 10 + line[i] - 48;
		i++;
	}
	if (swich < 1)
		return (error_flag("Not enough arguments on window size.\n"));
	return (GOOD_OUT);
}

char	*add_path(char *line, char *id)
{
	int		i;

	i = 0;
	while ((ft_strchr(id, line[i]) || line[i] == ' '))
		i++;
	return (line + i);
}

int		add_floor(char *line, t_map *file, char *id)
{
	int		i;
	char	swich;

	i = 0;
	swich = 0;
	while (ft_strchr(id, line[i]))
		i++;
	while (line[i] && swich <= 2)
	{
		if (!(ft_strchr("0123456789 ,\t", line[i])))
			return (error_flag("Floor color error.\n"));
		if (ft_strchr(" ,\t", line[i]))
		{
			swich++;
			while (ft_strchr(" ,\t", line[i + 1]))
				i++;
		}
		else
			file->f_color[swich] = (file->f_color[swich] * 10) + line[i] - 48;
		i++;
	}
	if (swich < 2)
		return (error_flag("Not enough arguments on floor color.\n"));
	return (GOOD_OUT);
}

int		add_ceiling(char *line, t_map *file, char *id)
{
	int		i;
	char	swich;

	i = 0;
	swich = 0;
	while (ft_strchr(id, line[i]))
		i++;
	while (line[i] && swich <= 2)
	{
		if (!(ft_strchr("0123456789 ,\t", line[i])))
			return (error_flag("Ceiling color error.\n"));
		if (ft_strchr(" ,\t", line[i]))
		{
			swich++;
			while (ft_strchr(" ,\t", line[i + 1]))
				i++;
		}
		else
			file->c_color[swich] = file->c_color[swich] * 10 + (line[i] - 48);
		i++;
	}
	if (swich < 2)
		return (error_flag("Not enough arguments on ceiling color.\n"));
	return (GOOD_OUT);
}

void	set_struct(t_map *file)
{
	file->win[0] = 0;
	file->win[1] = 0;
	file->f_color[0] = 0;
	file->f_color[1] = 0;
	file->f_color[2] = 0;
	file->c_color[0] = 0;
	file->c_color[1] = 0;
	file->c_color[2] = 0;
	file->n_path = 0;
	file->so_path = 0;
	file->we_path = 0;
	file->ea_path = 0;
	file->sp_path = 0;
}
