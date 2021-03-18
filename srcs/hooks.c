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

void	key_press(int key, t_char *player)
{
	if (key == W_KEY)
		player->keys.front = true;
	if (key == A_KEY)
		player->keys.wkleft = true;
	if (key == S_KEY)
		player->keys.back = true;
	if (key == D_KEY)
		player->keys.wkright = true;
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
	int	i;

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
	if (key == RIGHT_KEY)
		player->keys.right = true;
	if (key == LEFT_KEY)
		player->keys.left = true;
	if (key == ESC_KEY)
		return (clean_exit(player));
	if (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY)
		key_press(key, player);
	return (rendering(player));
}

int		mlx_hooks(t_char *player)
{
	int	ret;

	ret = 0;
	ret = mlx_hook(player->win, 2, (1L << 0), &key_hook, player);
	ret = mlx_hook(player->win, 3, (1L << 1), &key_release, player);
	ret = mlx_hook(player->win, 33, (1L << 17), &clean_exit, player);
	mlx_loop_hook(player->mlx, &rendering, player);
	return (ret);
}
