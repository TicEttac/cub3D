#include "cub3D.h"

t_point	wall_diff(float delta, t_char *player)
{
	t_point	res;

	res.x = (float)(cos(delta) > 0) - fmod(player->x, 1);
	res.y = (float)(sin(delta) > 0) - fmod(player->y, 1);
	return (res);
}

t_point	contact(t_char *player)
{
	t_point	res;

	res.x = player->x - fmod(player->x, 1);
	res.y = player->y - fmod(player->y, 1);
	return (res);
}

t_point	hypotenuse(t_point diff, float delta)
{
	t_point	res;

	res.x = fabs(diff.x) / fabs(cos(delta));
	res.y = fabs(diff.y) / fabs(sin(delta));
	return (res);
}

t_point	wall_dist_no_sprite(float delta, t_char *player)
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
		c[0].x = player->x + diff.x;
		c[0].y = player->y + tan(delta) * diff.x;
		c[1].x = player->x + diff.y / tan(delta);
		c[1].y = player->y + diff.y;
		if (fabs(hyp.x) < fabs(hyp.y))
		{
			cont = check_x(delta, c[0]);
			diff.x += (diff.x / fabs(diff.x));
		}
		else
		{
			cont = check_y(delta, c[1]);
			diff.y += (diff.y / fabs(diff.y));
		}
	}
	return (fabs(hyp.x) < fabs(hyp.y) ? c[0] : c[1]);
}
