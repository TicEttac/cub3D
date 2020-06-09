/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:24:53 by nisauvig          #+#    #+#             */
/*   Updated: 2020/05/24 23:40:15 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_map	file;
	int		index;
	int		i;

	index = 0;
	if (ac < 2)
		return (error_flag("No configuration path.\n"));
	if (!parser(av[1], &file))
		return (0);
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
	printf("\nwin x%d y%d\n", file.win[0], file.win[1]);
	printf("f color r%d g%d b%d\n", file.f_color[0],
	file.f_color[1], file.f_color[2]);
	printf("c color r%d g%d b%d\n", file.c_color[0],
	file.c_color[1], file.c_color[2]);
	mlx_start(&file);
	while (index >= 0)
	{
		free(file.map[index]);
		index--;
	}
	free(file.map);
	return (0);
}
