/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 01:19:17 by nisauvig          #+#    #+#             */
/*   Updated: 2020/08/07 01:19:59 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	key_mod(int key, t_char *player)
{
	t_point	ret;

	if (key == W_KEY)
	{
		ret.x = player->x + 0.1 * cos(player->dir);
		ret.y = player->y + 0.1 * sin(player->dir);
	}
	if (key == A_KEY)
	{
		ret.x = player->x + 0.1 * cos(player->dir + M_PI / 2);
		ret.y = player->y + 0.1 * sin(player->dir + M_PI / 2);
	}
	if (key == S_KEY)
	{
		ret.x = player->x - 0.1 * cos(player->dir);
		ret.y = player->y - 0.1 * sin(player->dir);
	}
	if (key == D_KEY)
	{
		ret.x = player->x - 0.1 * cos(player->dir + M_PI / 2);
		ret.y = player->y - 0.1 * sin(player->dir + M_PI / 2);
	}
	return (ret);
}

int		test_pos(t_point next, t_tile **map)
{
	if (map[(int)(next.x - fmod(next.x, 1))]
				[(int)(next.y - fmod(next.y, 1))].tile == ' ')
		return (1);
	return (0);
}

int		clean_exit(t_char *player)
{
	int		i;

	i = player->file->mapH;
	mlx_destroy_image(player->mlx, player->image.img);
	mlx_clear_window(player->mlx, player->win);
	mlx_destroy_window(player->mlx, player->win);
	while (i >= 0)
	{
		free(player->file->map[i]);
		i--;
	}
	exit(0);
	return (0);
}

int		key_hook(int key, t_char *player)
{
	t_point	next;

	if (key == RIGHT_KEY)
		player->dir -= M_PI / 25;
	if (key == LEFT_KEY)
		player->dir += M_PI / 25;
	if (key == ESC_KEY)
		return (clean_exit(player));
	if (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY)
	{
		next = key_mod(key, player);
		if (test_pos(next, player->file->map))
		{
			player->x = next.x;
			player->y = next.y;
		}
	}
	return (rendering(player));
}

int		mlx_hooks(t_char *player)
{
	int		ret;

	ret = 0;
	rendering(player);
	ret = mlx_hook(player->win, 2, 0, &key_hook, player);
	return (ret);
}