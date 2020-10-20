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
	t_point	c[2];
	t_point	cont;

	diff = wall_diff(delta, player);
	cont = contact(player);
	while (player->file->map[(int)cont.x][(int)cont.y].tile != '1')
	{
		hyp = hypotenuse(diff, delta);
		if (fabs(hyp.x) < fabs(hyp.y))
		{
			c[0].x = player->x + diff.x;
			c[0].y = player->y + tan(delta) * diff.x; //y = ... * diff.x is normal
			cont = check_x(delta, c[0]);
			diff.x += (diff.x / fabs(diff.x));
		}
		else
		{
			c[1].x = player->x + diff.y / tan(delta);
			c[1].y = player->y + diff.y;
			cont = check_y(delta, c[1]);
			diff.y += (diff.y / fabs(diff.y));
		}
		if (ft_strchr("2", player->file->map[(int)cont.x][(int)cont.y].tile))
			player->sprite = true;
	}
	return (fabs(hyp.x) < fabs(hyp.y) ? c[0] : c[1]);
}

int		rendering(t_char *player)
{
	int		segment;
	float	delta_ray;
	t_point	cont;
	void	*img;
	int		*tab;

	segment = 0;
	cont = key_mod(player);
	if (test_pos(cont, player->file->map))
	{
		player->x = cont.x;
		player->y = cont.y;
	}
	mlx_clear_window(player->mlx, player->win);
	delta_ray = player->dir + (FOV / 2);
	while (segment <= player->file->win[0])
	{
		player->sprite = false;
		cont = wall_dist(delta_ray, player);
		apply_ray(cont, player, delta_ray, segment);
		if (player->sprite == true)
			sprite(player, cont, segment, delta_ray);
		segment++;
		delta_ray -= FOV / player->file->win[0];
	}
	mlx_put_image_to_window(player->mlx, player->win, player->image.img, 0, 0);
	return (0);
}
