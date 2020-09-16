/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:24:53 by nisauvig          #+#    #+#             */
/*   Updated: 2020/08/07 01:21:36 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

t_char	set_character(t_map *file)
{
	t_char	player;
	char	card;

	card = file->map[(int)file->start[0]][(int)file->start[1]].content;
	player.x = file->start[0] + 0.5;
	player.y = file->start[1] + 0.5;
	player.file = file;
	player.dir = card == 'E' ? M_PI / 2 : 0;
	player.dir = card == 'W' ? M_PI + (M_PI / 2) : player.dir;
	player.dir = card == 'N' ? M_PI : player.dir;
	return (player);
}

int		print_infos(t_map file)
{
	int		index;
	int		i;

	index = 0;
	i = 0;
	while (file.map[index][0].tile != '\0')
	{
		i = 0;
		while (file.map[index][i].tile != '\0')
		{
			printf("%c", file.map[index][i].tile);
			i++;
		}
		printf("\n");
		index++;
	}
	i = 0;
/*	printf("\nwin x%d y%d\n", file.win[0], file.win[1]);
	printf("f color r%d g%d b%d\n", file.f_color[0],
	file.f_color[1], file.f_color[2]);
	printf("c color r%d g%d b%d\n", file.c_color[0],
	file.c_color[1], file.c_color[2]);
*/	return (index);
}

int		main(int ac, char **av)
{
	t_map	file;
	int		index;
	t_char	player;

	int		i;
	i = 0;

	if (ac < 2)
		return (error_flag("No configuration path.\n"));
	if (!parser(av[1], &file))
		return (0);
	player = set_character(&file);
	index = print_infos(file);
	printf("mapH=%d, mapW=%d\n", file.mapH, file.mapW);
	mlx_start(&file, &player);
	init_image(&player);
	mlx_hooks(&file, &player);
	mlx_loop(player.mlx);
	while (index >= 0)
	{
		free(file.map[index]);
		index--;
	}
	free(file.map);
	return (0);
}
