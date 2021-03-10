/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <nisauvig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:25:01 by nisauvig          #+#    #+#             */
/*   Updated: 2021/03/09 19:57:00 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_fullfilled(t_map *file)
{
	if (!(file->win[0] && file->win[1]))
		return (0);
	if (!(file->f_color[0] || file->f_color[1] || file->f_color[2]))
		return (0);
	if (!(file->c_color[0] || file->c_color[1] || file->c_color[2]))
		return (0);
	if (file->n_path.tex == 0)
		return (0);
	if (file->so_path.tex == 0)
		return (0);
	if (file->ea_path.tex == 0)
		return (0);
	if (file->we_path.tex == 0)
		return (0);
	if (file->sp_path.tex == 0)
		return (0);
	return (1);
}

void	print_map(t_tile **map)
{
	int	x;
	int	y;

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

int		get_tight(char *s, char **dtab, int size)
{
	free_dtab(dtab, size);
	error_flag(s);
	return (BAD_OUT);
}

int		straw_man(int *index, int *i_map, char **conf_file, t_map *file)
{
	int	i;

	if ((i = translate_map(*index, *i_map, conf_file, file)) == BAD_OUT)
		return (BAD_OUT);
	file->mapW = i - 1 > file->mapW ? i - 1 : file->mapW;
	file->map[*i_map][i].tile = '\0';
	file->map[*i_map][i].content = '\0';
	*index += 1;
	*i_map += 1;
	return (GOOD_OUT);
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
