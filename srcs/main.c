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
	ft_bzero(&player, sizeof(t_char));
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
	return (index);
}

int		main(int ac, char **av)
{
	t_map		file;
	int		index;
	t_char		player;

	if (ac < 2 || ac > 3 || (ac == 3 && ft_strcmp(av[2], "--save")))
		return (error_flag("Wrong arguments.\n"));
	if (!parser(av[1], &file))
		return (0);
	player = set_character(&file);
	player.save = (ac == 3 && !ft_strcmp(av[2], "--save")) ? 1 : 0;
	printf("px%f py%f\n", player.x, player.y);
	index = print_infos(file);
	printf("mapH=%d, mapW=%d\n", file.mapH, file.mapW);
	mlx_start(&player);
	init_image(&player);
	mlx_hooks(&player);
	mlx_loop(player.mlx);
	while (index >= 0)
	{
		free(file.map[index]);
		index--;
	}
	free(file.map);
	return (0);
}
