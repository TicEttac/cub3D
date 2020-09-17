/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 23:39:37 by nisauvig          #+#    #+#             */
/*   Updated: 2020/08/04 17:32:55 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		mlx_start(t_char *player)
{
	char	*path;
	int		i;

	i = 0;
	printf("player.x=%f player.y=%f\n", player->x, player->y);
	if (!(player->mlx = mlx_init()))
		return (error_flag("MLX error : funct. init doesn't work.\n"));
	if (!(player->win = mlx_new_window(player->mlx,
					player->file->win[0], player->file->win[1], "cub3D")))
		return (error_flag("MLX error : funct. new_window doesn't work.\n"));
	if (!load_texture(player))
		return (BAD_OUT);
	return (GOOD_OUT);
}

t_point	check_x(float delta, t_point addx)
{
	t_point	ret;

	ret.x = addx.x - (float)(cos(delta) < 0);
	ret.y = addx.y - fmod(addx.y, 1);
	return (ret);
}

t_point	check_y(float delta, t_point addy)
{
	t_point	ret;

	ret.x = addy.x - fmod(addy.x, 1);
	ret.y = addy.y - (float)(sin(delta) < 0);
	return (ret);
}

t_point	wall_dist(float delta, t_char *player)
{
	t_point	diff;
	t_point	hyp;
	t_point	cx;
	t_point	cy;
	t_point	cont;

	diff.x = (float)(cos(delta) > 0) - fmod(player->x, 1);
	diff.y = (float)(sin(delta) > 0) - fmod(player->y, 1);
	cont.x = player->x - fmod(player->x, 1);
	cont.y = player->y - fmod(player->y, 1);
	while (player->file->map[(int)cont.x][(int)cont.y].tile != '1')
	{
		hyp.x = fabs(diff.x) / fabs(cos(delta));
		hyp.y = fabs(diff.y) / fabs(sin(delta));
		cx.x = player->x + diff.x;
		cx.y = player->y + tan(delta) * fabs(diff.x); //y = ... * diff.x is normal
		cy.x = player->x + diff.y / tan(delta);
		cy.y = player->y + diff.y;
		if (fabs(hyp.x) < fabs(hyp.y))
		{
			cont = check_x(delta, cx);
			diff.x += (diff.x / fabs(diff.x));
		}
		else
		{
			cont = check_y(delta, cy);
			diff.y += (diff.y / fabs(diff.y));
		}
	}
	return (fabs(hyp.x) < fabs(hyp.y) ? cx : cy);
}

int		rendering(t_char *player)
{
	int		segment;
	float	delta_ray;
	t_point	cont;
	void	*img;
	int		*tab;

	segment = 0;
	mlx_clear_window(player->mlx, player->win);
	delta_ray = player->dir + (FOV / 2);
	while (segment <= player->file->win[0])
	{
		cont = wall_dist(delta_ray, player);
		apply_ray(cont, player, delta_ray, segment);
		segment++;
		delta_ray -= FOV / player->file->win[0];
	}
	mlx_put_image_to_window(player->mlx, player->win, player->image.img, 0, 0);
	return (0);
}
