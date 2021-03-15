/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <nisauvig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:01:46 by nisauvig          #+#    #+#             */
/*   Updated: 2021/03/15 15:01:58 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		coloring(int color, int s[2], int bound, t_char *player)
{
	while (s[0] < bound)
	{
		player->image.tab[s[0]] = color;
		s[0] += s[1];
	}
	return (s[0]);
}

float	test_fuck(float delta, t_point cnt, t_point center, float dist)
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
	else if (cos(delta) < 0.0)
		if (cnt.y <= center.y)
			return (dist + 0.5);
		else
			return (0.5 - dist);
	else if (cnt.y < center.y)
		return (0.5 - dist);
	else
		return (dist + 0.5);
}
