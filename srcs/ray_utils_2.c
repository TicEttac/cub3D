#include "cub3D.h"

t_point		sprite_dist(float delta, t_point cnt, t_tile **map, t_point player)
{
	t_point	diff;
	t_point	hyp;
	t_point	c[2];
	t_point	cont;
	int		i;

	diff = wall_diff(delta, player);
	cont = contact(cnt);
	i = 0;
	c[i] = cnt;
	while (map[(int)cont.x][(int)cont.y].tile != '2')
	{
		if ((int)c[i].x == (int)player.x && (int)c[i].y == (int)player.y)
			break;
		hyp = hypotenuse(diff, delta);
		if (fabs(hyp.x) < fabs(hyp.y))
		{
			i = 0;
			c[0].x = cnt.x + diff.x;
			c[0].y = cnt.y + tan(delta) * diff.x; //y = ... * diff.x is normal
			cont = check_x(delta, c[0]);
			diff.x += (diff.x / fabs(diff.x));
		}
		else
		{
			i = 1;
			c[1].x = cnt.x + diff.y / tan(delta);
			c[1].y = cnt.y + diff.y;
			cont = check_y(delta, c[1]);
			diff.y += (diff.y / fabs(diff.y));
		}
		if (map[(int)c[i].x][(int)c[i].y].tile == '1')
			break;
	}
	return (c[i]);
}

float test_fuck(float delta, t_point cnt, t_point center, float dist)
{
	t_point	diff;
	t_point	hyp;

	diff = wall_diff(delta, cnt);
	hyp = hypotenuse(diff, delta);
	if (fabs(hyp.x) < fabs(hyp.y))
		if (sin(delta) < 0.0)
			if (cnt.x > center.x)
				return (0.5 - dist);
			else
				return (dist + 0.5);
		else if (cnt.x <= center.x && sin(delta) > 0.0)
			return (dist + 0.5);
		else
			return (0.5 - dist);
	else
		if (cos(delta) < 0.0)
			if (cnt.y <= center.y)
				return (dist + 0.5);
			else
				return (0.5 - dist);
		else if (cnt.y < center.y)
			return (0.5 - dist);
		else
			return (dist + 0.5);
}
