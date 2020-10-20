#include "cub3D.h"

static float	test_fuck(t_char *player, t_point cnt, t_point center, float ray)
{
	return (0.0);
	//if (cos(ray))
}
static float	fdist(float x, float y, float to_x, float to_y)
{
	return (sqrtf(powf(x - to_x, 2) + powf(y - to_y, 2)));
}

static int		calc_line(t_char *player, t_point cnt, int seg, float ray)
{
	float		coef_va;
	float		coef_vj;
	float		vj_b;
	float		va_b;
	float		dist;
	int			line;
	t_point		center;
	t_point		cont;

	coef_va = (cnt.y - player->y) / (cnt.x - player->x);
	va_b = cnt.y - (coef_va * cnt.x);
	coef_vj = -(1 / coef_va);
	center.x = cnt.x - fmod(cnt.x, 1) + 0.5;
	center.y = cnt.y - fmod(cnt.y, 1) + 0.5;
	vj_b = center.y - (coef_vj * center.x);
	cont.x = (vj_b - va_b) / (coef_va - coef_vj);
	cont.y = coef_va * (vj_b - va_b) / (coef_va - coef_vj) + va_b;
	dist = fdist(center.x, center.y, cont.x, cont.y);
	//printf("dist %f\n", dist);
	line = (int)((dist + test_fuck(player, cont, center, ray)) * player->file->sp_path.width);
	return (line);
}

static void		swap_floats(float *x, float *y, float *to_x, float *to_y)
{
	t_point		tmp;

	tmp.x = *x;
	tmp.y = *y;
	*x = *to_x;
	*y = *to_y;
	*to_x = tmp.x;
	*to_y = tmp.y;
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
	{
		player->image.tab[x] = player->file->c_color[0];
		x += player->file->win[0];
	}
	tmp_i = x / player->file->win[0];
	y = fmod((!fmod(tex.cnt.x, 1) ? tex.cnt.y : tex.cnt.x) , 1) * tex.width;
	while (x < (tmp_i + wall) * player->file->win[0])
	{
		player->image.tab[x] = tex.tab[(int)((int)y + (int)((float)(x / player->file->win[0] - tmp_i) * (float)(tex.height / wall)) * tex.width)];
		x += player->file->win[0];
	}
	while (x < (player->file->win[1] - 1) * player->file->win[0])
	{
		player->image.tab[x] = player->file->f_color[0];
		x += player->file->win[0];
	}
}

void			sprite(t_char *player, t_point cnt, int seg, float ray)
{
	int			line;
	float		tot;
	float		part;
	t_sprite	sp;
	t_point		wall;

	wall.x = cnt.x;
	wall.y = cnt.y;
	tot = fdist(player->x, player->y, cnt.x, cnt.y);
	swap_floats(&cnt.x, &cnt.y, &player->x, &player->y);
	part = 0.0;
	while ((part / tot) < 1.0)
	{
		sp.pos = sprite_dist(ray + M_PI, player);
		part = fdist(sp.pos.x, sp.pos.y, wall.x, wall.y);
		printf("part=%f, tot=%f\n", part, tot);
		swap_floats(&cnt.x, &cnt.y, &player->x, &player->y);
		sp.line = calc_line(player, cnt, seg, ray);
		player->file->sp_path.cnt = sp.pos;
		cnt = sp.pos;
		print_sprite(sp, player, seg, player->file->sp_path);
		swap_floats(&cnt.x, &cnt.y, &player->x, &player->y);
	}
	swap_floats(&cnt.x, &cnt.y, &player->x, &player->y);
}
