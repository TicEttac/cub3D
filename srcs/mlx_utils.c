/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:24:38 by nisauvig          #+#    #+#             */
/*   Updated: 2020/08/07 00:38:29 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		set_color(int col[3])
{
	return (65536 * col[0] + 256 * col[1] + col[2]);
}

int		colum_fill(t_char *player, int seg, int hex)
{
	int		i;

	i = 0;
	while (i < player->file->win[1] - 1)
	{
		player->image.tab[seg] = hex;
		seg += player->file->win[0];
		i++;
	}
	return (0);
}

int		column_trace(t_char *player, float hyp, int seg, int hex)
{
	float	wall;
	int		i;
	int		temp_i;
	int		color;
	long	x;

	if ((wall = (player->file->win[1] / (2 * fabs(hyp))) * 2) >= player->file->win[1] - 1)
		return (colum_fill(player, seg, hex));
	i = 0;
	x = seg;
	color = set_color(player->file->c_color);
	while (i < (player->file->win[1] - wall) / 2)
	{
		player->image.tab[x] = color;
		x += player->file->win[0];
		i++;
	}
	temp_i = i;
	while (i < temp_i + wall)
	{
		player->image.tab[x] = hex;
		x += player->file->win[0];
		i++;
	}
	color = set_color(player->file->f_color);
	while (i < player->file->win[1] - 1)
	{
		player->image.tab[x] = color;
		x += player->file->win[0];
		i++;
	}
	return (0);
}

int		apply_ray(t_point cnt, t_char *player, float ray, int seg)
{
	float	hyp;

	if (!fmod(cnt.x, 1))
	{
		write(1, "contact X\n", 10);
		hyp = (fabs(cnt.x - player->x) / cos(ray));
		if (cos(ray) < 0)
			column_trace(player, hyp, seg, RED);
		else
			column_trace(player, hyp, seg, BLUE);
	}
	else
	{
		write(1, "contact Y\n", 10);
		hyp = (fabs(cnt.y - player->y) / sin(ray));
		if (sin(ray) < 0)
			column_trace(player, hyp, seg, YELLOW);
		else
			column_trace(player, hyp, seg, GREEN);
	}
	return (0);
}

void	init_image(t_char *player)
{
	int		bpp;
	int		endian;

	bpp = 32;
	endian = 0;
	player->image.img = mlx_new_image(player->mlx, player->file->win[0]
	, player->file->win[1]);
	player->image.sl = player->file->win[0];
	player->image.tab = (int*)mlx_get_data_addr(player->image.img, &bpp,
	&player->image.sl, &endian);
	rendering(player->file, player);
}
