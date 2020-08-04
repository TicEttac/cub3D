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
	float	dist;
	int		i;
	int		temp_i;

	dist = 1 / hyp;
	i = 0;
	while (i < (dist > 1.0 ? (int)((file->win[0] - dist * file->win[0]) / 2) :
				0))
	{
		mlx_pixel_put(player->mlx, player->win, i,
				seg, set_color(file->c_color));
		i++;
	}
	temp_i = i;
	while (i < (dist > 1.0 ? temp_i + (int)(dist * file->win[0]) : file->win[0]))
	{
		mlx_pixel_put(player->mlx, player->win, i, seg, hex);
		i++;
	}
	temp_i = i;
	while (i < (file->win[0] - temp_i))
	{
		mlx_pixel_put(player->mlx, player->win, i,
				seg, set_color(file->f_color));
		i++;
	}
	return (0);
}

int		aply_ray(t_point cnt, t_char *player, t_map *file, float ray, int seg)
{
	float	hyp;

	hyp = sqrt(powf(cnt.x - player->x, 2) + powf(cnt.y - player->y, 2));
	printf("hyp=%f\n", hyp);
	if (!fmod(player->x, 1))
	{
		if (cos(ray) < 0)
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
