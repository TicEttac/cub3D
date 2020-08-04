/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:24:38 by nisauvig          #+#    #+#             */
/*   Updated: 2020/08/04 18:43:01 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		set_color(int col[3])
{
	return (65536 * col[0] + 256 * col[1] + col[2]);
}

int		column_trace(t_char *player, t_map *file, float hyp, int seg, int hex)
{
	float	wall;
	int		i;
	int		temp_i;

	wall = (file->win[1] / (2 * hyp)) * 2;
	i = 0;
	while (i < (file->win[1] - wall) / 2)
	{
		mlx_pixel_put(player->mlx, player->win, seg,
				i, set_color(file->c_color));
		i++;
	}
	temp_i = i;
	while (i < temp_i + wall)
	{
		mlx_pixel_put(player->mlx, player->win, seg, i, hex);
		i++;
	}
	temp_i = i;
	while (i < file->win[1])
	{
		mlx_pixel_put(player->mlx, player->win, seg, i,
		set_color(file->f_color));
		i++;
	}
	return (0);
}

int		aply_ray(t_point cnt, t_char *player, t_map *file, float ray, int seg)
{
	float	hyp;

	hyp = fabs(cnt.x - player->x) / cos(ray);
	printf("hyp=%f\n", hyp);
	if (!fmod(cnt.x, 1))
	{
		if (fmod(cnt.y, 1) < 0.001)
			column_trace(player, file, hyp, seg, BLACK);
		else if (cos(ray) < 0)
			column_trace(player, file, hyp, seg, RED);
		else
			column_trace(player, file, hyp, seg, BLUE);
	}
	else
	{
		if (sin(ray) < 0)
			column_trace(player, file, hyp, seg, YELLOW);
		else
			column_trace(player, file, hyp, seg, GREEN);
	}
	return (0);
}
