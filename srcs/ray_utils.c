#include "cub3D.h"

t_point	wall_diff(float delta, t_point player)
{
	t_point	res;

	res.x = (float)(cos(delta) > 0) - fmod(player.x, 1.0);
	res.y = (float)(sin(delta) > 0) - fmod(player.y, 1.0);
	return (res);
}

t_point	contact(t_point player)
{
	t_point	res;

	res.x = (int)player.x;
	res.y = (int)player.y;
	return (res);
}

t_point	hypotenuse(t_point diff, float delta)
{
	t_point	res;

	res.x = fabs(diff.x) / fabs(cos(delta));
	res.y = fabs(diff.y) / fabs(sin(delta));
	return (res);
}
