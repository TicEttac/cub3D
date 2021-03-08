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

int     colum_fill(t_char *player, float wall, long seg, t_tex tex)
{
	int     i;
	int     px;
	long    col;
	float   texmarge;

	i = 0;
	texmarge = tex.height * (float)(wall - player->file->win[1]) / wall;
	col = (long)(fmod((!fmod(tex.cnt.x, 1) ? tex.cnt.y : tex.cnt.x) , 1) * tex.width);
	while (i < player->file->win[1] - 1)
	{
		player->image.tab[seg] = tex.tab[col + (long)(texmarge / 2 + (tex.height - texmarge) * ((float)seg / player->file->win[0] / player->file->win[1])) * tex.width];
		seg += player->file->win[0];
		i++;
	}
	return (0);
}

int		column_trace(t_char *player, float hyp, int seg, t_tex tex)
{
	float	wall;
	int		tmp_i;
	int		color;
	long	x;
	long	y;

	if ((wall = (player->file->win[1] / (2 * fabs(hyp))) * 2) >= player->file->win[1] - 1)
		return (colum_fill(player, wall, seg, tex));
	x = seg;
	while (x < ((player->file->win[1] - wall) / 2) * player->file->win[0])
	{
		player->image.tab[x] = player->file->c_color[0];
		x += player->file->win[0];
	}
	tmp_i = x / player->file->win[0];
	y = fmod((!fmod(tex.cnt.x, 1) ? tex.cnt.y : tex.cnt.x) , 1) * tex.width;
	while (x < (tmp_i + wall) * player->file->win[0])
	{
		player->image.tab[x] = tex.tab[(int)((int)y + (int)((float)(x / player->file->win[0] - tmp_i) * (float)(tex.height / wall)) * tex.width)];
		x += player->file->win[0];
	}
	while (x < (player->file->win[1] - 1) * player->file->win[0])
	{
		player->image.tab[x] = player->file->f_color[0];
		x += player->file->win[0];
	}
	return (0);
}

int		apply_ray(t_point cnt, t_char *player, float ray, int seg)
{
	float	hyp;
	t_tex	tex;

	if (!fmod(cnt.x, 1))
	{
		hyp = (fabs(cnt.x - player->x) / cos(ray));
		if (cos(ray) < 0)
			tex = player->file->n_path;
		else
			tex = player->file->so_path;
	}
	else
	{
		hyp = (fabs(cnt.y - player->y) / sin(ray));
		if (sin(ray) < 0)
			tex = player->file->ea_path;
		else
			tex = player->file->we_path;
	}
	tex.cnt = cnt;
	column_trace(player, hyp, seg, tex);
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
	//player->image.sl = player->file->win[0];
	player->image.tab = (int*)mlx_get_data_addr(player->image.img, &bpp,
	&player->image.sl, &endian);
	printf("Save stat %d\n", player->save);
	rendering(player);
}
