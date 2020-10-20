#include "cub3D.h"

static int	ft_inchar(char c, char *s)
{
	int ret;
	int	i;

	i = 0;
	while (s[i])
		if (s[i] == c)
			return (1);
		else
			i++;
	return (0);
}

t_point		sprite_dist(float delta, t_char *player)
{
	t_point	diff;
	t_point	hyp;
	t_point	c[2];
	t_point	cont;

	diff = wall_diff(delta, player);
	cont = contact(player);
	while (!ft_inchar(player->file->map[(int)cont.x][(int)cont.y].tile, "12"))
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
	}
	return (fabs(hyp.x) < fabs(hyp.y) ? c[0] : c[1]);
}

float test_fuck(float delta, t_char *player, t_point cnt, t_point center)
{
	t_point	diff;
	t_point	hyp;
	t_point	c[2];

	diff = wall_diff(delta, player);
	hyp = hypotenuse(diff, delta);
	if (fabs(hyp.x) < fabs(hyp.y))
	{
		if (sin(delta) > 0)
			if (cnt.x < center.x)
				return (0.5);
			else
				return (0.0);
		else if (cnt.x > center.x)
				return (0.5);
	}
	else
	{
		if (cos(delta) > 0)
			if (cnt.y < center.y)
				return (0.5);
			else
				return (0.0);
		else if (cnt.y > center.y)
				return (0.5);
	}
	return (0);
}
