#include "cub3D.h"

static float	fdist(float x, float y, float to_x, float to_y)
{
	return (sqrtf(powf(x - to_x, 2) + powf(y - to_y, 2)));
}

static int		calc_line(t_char *player, t_point *cnt, int seg, float ray)
{
	float		coef_va;
	float		coef_vj;
	float		vj_b;
	float		va_b;
	float		dist;
	t_point		center;

	coef_va = (cnt->y - player->y) / (cnt->x - player->x);
	va_b = cnt->y - (coef_va * cnt->x);
	coef_vj = -(1 / coef_va);
	center.x = (int)(cnt->x) + 0.5;
	center.y = (int)(cnt->y) + 0.5;
	vj_b = center.y - (coef_vj * center.x);
	cnt->x = (vj_b - va_b) / (coef_va - coef_vj);
	cnt->y = (coef_va * (vj_b - va_b)) / (coef_va - coef_vj) + va_b;
	if ((dist = fdist(center.x, center.y, cnt->x, cnt->y)) > 0.5)
		return (-1);
	return ((int)(test_fuck(ray, *cnt, center, dist) * player->file->sp_path.width));
}

void			print_sprite(t_sprite sp, t_char *player, int seg, t_tex tex)
{
	float	wall;
	int		tmp_i;
	int		color;
	long	x;
	long	y;
	float	hyp;

	hyp = fdist(player->x, player->y, sp.pos.x, sp.pos.y);
	if ((wall = (player->file->win[1] / (2 * fabs(hyp))) * 2) >= player->file->win[1] - 1)
		return ((void)colum_fill(player, wall, seg, tex));
	x = seg;
	while (x < ((player->file->win[1] - wall) / 2) * player->file->win[0])
		x += player->file->win[0];
	tmp_i = x / player->file->win[0];
	y = sp.line;
	while (x < (tmp_i + wall) * player->file->win[0])
	{
		if (tex.tab[(int)((int)y + (int)((float)(x / player->file->win[0] - tmp_i) * (float)(tex.height / wall)) * tex.width)])
			player->image.tab[x] = tex.tab[(int)((int)y + (int)((float)(x / player->file->win[0] - tmp_i) * (float)(tex.height / wall)) * tex.width)];
		x += player->file->win[0];
	}
	while (x < (player->file->win[1] - 1) * player->file->win[0])
		x += player->file->win[0];
}

static t_point	past_sprite(t_sprite sp, float delta)
{
	t_point	diff;
	t_point	hyp;
	t_point	c[2];

	diff = wall_diff(delta, sp.pos);
	//printf("diff %f %f\n", diff.x, diff.y);
	hyp = hypotenuse(diff, delta);
	//printf("hyp %f %f\n", hyp.x, hyp.y);
	if (fabs(hyp.x) < fabs(hyp.y))
	{
		c[0].x = sp.pos.x + diff.x;
		c[0].y = sp.pos.y + tan(delta) * diff.x; //y = ... * diff.x is normal
		return (c[0]);
	}
	else
	{
		c[1].x = sp.pos.x + diff.y / tan(delta);
		c[1].y = sp.pos.y + diff.y;
		return (c[1]);
	}
}

void			sprite(t_char *player, t_point cnt, int seg, float ray)
{
	float		tot;
	float		part;
	t_sprite	sp;
	t_point		wall;

	wall.x = cnt.x;
	wall.y = cnt.y;
	tot = fdist(player->x, player->y, cnt.x, cnt.y);
	part = 0.0;
	//printf("cnt %f %f\n", cnt.x, cnt.y);
	while ((part / tot) < 1.0)
	{
		//printf("A pos %f %f\n", sp.pos.x, sp.pos.y);
		sp.pos = sprite_dist(ray + M_PI, cnt, player->file->map, (t_point){player->x, player->y});
		if (((int)sp.pos.x == (int)player->x && (int)sp.pos.y == (int)player->y) || sp.pos.x < 0 || sp.pos.y < 0
											|| (player->file->map[(int)sp.pos.x][(int)sp.pos.y].tile == '1'))
			return ;
		//printf("B pos %f %f\n", sp.pos.x, sp.pos.y);
		if ((sp.line = calc_line(player, &sp.pos, seg, ray + M_PI)) == -1)
			return ;
		player->file->sp_path.cnt = sp.pos;
		print_sprite(sp, player, seg, player->file->sp_path);
		part = fdist(sp.pos.x, sp.pos.y, wall.x, wall.y);
		//printf("C pos %f %f\n", sp.pos.x, sp.pos.y);
		sp.pos = past_sprite(sp, ray + M_PI);
		cnt = sp.pos;
	}
}
