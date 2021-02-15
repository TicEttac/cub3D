#include "cub3D.h"



float		test_fuck(float delta, t_point cnt, t_point center, float dist)
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
