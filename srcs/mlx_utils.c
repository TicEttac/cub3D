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

int		colum_fill(t_char *player, float wall, int seg, t_tex tex)
{
	int		i;
	int		px;
	int		col;

	i = 0;
	px = (wall - player->file->win[1]) / 2;
	col = fmod(tex.cnt.x, 1) ? fmod(tex.cnt.x, 1) * tex.width + px :
			fmod(tex.cnt.y, 1) * tex.width + px;
	while (i < player->file->win[1] - 1)
	{
		player->image.tab[seg] = tex.tex[col];
		seg += player->file->win[0];
		i++;
		col += tex.width;
	}
	return (0);
}

int		column_trace(t_char *player, float hyp, int seg, t_tex tex)
{
	float	wall;
	int		i;
	int		tmp_i;
	int		color;
	long	x;
	int		col;

	if ((wall = (player->file->win[1] / (2 * fabs(hyp))) * 2) >= player->file->win[1] - 1)
		return (colum_fill(player, wall, seg, tex));
	printf("wall = %f\n", wall);
	i = 0;
	x = seg;
	while (i < (player->file->win[1] - wall) / 2)
	{
		player->image.tab[x] = player->file->c_color[0];
		x += player->file->win[0];
		i++;
	}
	tmp_i = i;
	col = !fmod(tex.cnt.x, 1) ? fmod(tex.cnt.y, 1) : fmod(tex.cnt.x, 1);
	while (i < tmp_i + wall)
	{
		player->image.tab[x] = tex.tex[(int)(((i - tmp_i) * tex.width / wall) + col)];
		x += player->file->win[0];
		i++;
	}
	while (i < player->file->win[1] - 1)
	{
		player->image.tab[x] = player->file->f_color[0];
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
		hyp = (fabs(cnt.x - player->x) / cos(ray));
		if (cos(ray) < 0)
		{
			player->file->n_path.cnt = cnt;
			column_trace(player, hyp, seg, player->file->n_path);
		}
		else
		{
			player->file->n_path.cnt = cnt;
			column_trace(player, hyp, seg, player->file->so_path);
		}
	}
	else
	{
		hyp = (fabs(cnt.y - player->y) / sin(ray));
		if (sin(ray) < 0)
		{
			player->file->n_path.cnt = cnt;
			column_trace(player, hyp, seg, player->file->ea_path);
		}
		else
		{
			player->file->n_path.cnt = cnt;
			column_trace(player, hyp, seg, player->file->we_path);
		}
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
	rendering(player);
}
