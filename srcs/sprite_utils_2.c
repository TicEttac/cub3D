#include "cub3D.h"

int		sprite_fill(t_char *player, float wall, long seg, t_tex tex)
{
	int		i;
	long	col;
	float	texmarge;

	i = 0;
	texmarge = tex.height * (float)(wall - player->file->win[1]) / wall;
	if (!fmod(tex.cnt.x, 1))
		col = (long)(fmod(tex.cnt.y, 1) * tex.width);
	else
		col = (long)(fmod(tex.cnt.x, 1) * tex.width);
	while (i < player->file->win[1] - 1)
	{
		if (tex.tab[col + (long)(texmarge / 2 + (tex.height - texmarge)
		* ((float)seg / player->file->win[0] / player->file->win[1]))
		* tex.width])
			player->image.tab[seg] = tex.tab[col + (long)(texmarge
			/ 2 + (tex.height - texmarge) * ((float)seg / player->file->win[0]
			/ player->file->win[1])) * tex.width];
		seg += player->file->win[0];
		i++;
	}
	return (0);
}

int		one_step(t_tamer tamer, t_point *cont, t_point *diff, t_point *c)
{
	int		i;
	t_point	hyp;

	hyp = hypotenuse(*diff, tamer.delta);
	if (fabs(hyp.x) < fabs(hyp.y))
	{
		i = 0;
		c[0].x = tamer.cnt.x + diff->x;
		c[0].y = tamer.cnt.y + tan(tamer.delta) * diff->x;
		*cont = check_x(tamer.delta, *c);
		diff->x += (diff->x / fabs(diff->x));
	}
	else
	{
		i = 1;
		c[1].x = tamer.cnt.x + diff->y / tan(tamer.delta);
		c[1].y = tamer.cnt.y + diff->y;
		*cont = check_y(tamer.delta, *(c + 1));
		diff->y += (diff->y / fabs(diff->y));
	}
	return (i);
}

t_point	sprite_dist(float delta, t_point cnt, t_tile **map, t_point player)
{
	t_point	diff;
	t_point	c[2];
	t_point	cont;
	int		i;

	diff = wall_diff(delta, player);
	cont = contact(cnt);
	i = 0;
	c[i] = cnt;
	while (map[(int)cont.x][(int)cont.y].tile != '2' || (map[(int)cnt.x]
	[(int)cnt.y].tile == '2' && ((cos(delta) < 0.0 && !fmod(cnt.x, 1))
	|| (sin(delta) < 0.0 && !fmod(cnt.y, 1)))))
	{
		if ((int)c[i].x == (int)player.x && (int)c[i].y == (int)player.y)
			break ;
		i = one_step((t_tamer){delta, cnt}, &cont, &diff, c);
		if (map[(int)c[i].x][(int)c[i].y].tile == '1')
			break ;
	}
	return (c[i]);
}
