#include "cub3D.h"

t_point	wk_right(t_char *player)
{
	t_point	ret;

	ret.x = player->x - SPEED * cos(player->dir + M_PI / 2);
	ret.y = player->y - SPEED * sin(player->dir + M_PI / 2);
	return (ret);
}

t_point	wk_left(t_char *player)
{
	t_point	ret;

	ret.x = player->x + SPEED * cos(player->dir + M_PI / 2);
	ret.y = player->y + SPEED * sin(player->dir + M_PI / 2);
	return (ret);
}

t_point	key_mod(t_char *player)
{
	t_point	ret;

	ret.x = player->x;
	ret.y = player->y;
	if (player->keys.front)
	{
		ret.x = player->x + SPEED * cos(player->dir);
		ret.y = player->y + SPEED * sin(player->dir);
	}
	if (player->keys.wkleft)
		ret = wk_left(player);
	if (player->keys.back)
	{
		ret.x = player->x - SPEED * cos(player->dir);
		ret.y = player->y - SPEED * sin(player->dir);
	}
	if (player->keys.wkright)
		ret = wk_right(player);
	if (player->keys.left)
		player->dir += M_PI / 25;
	if (player->keys.right)
		player->dir -= M_PI / 25;
	return (ret);
}

int		key_release(int key, t_char *player)
{
	if (key == W_KEY)
		player->keys.front = false;
	if (key == A_KEY)
		player->keys.wkleft = false;
	if (key == S_KEY)
		player->keys.back = false;
	if (key == D_KEY)
		player->keys.wkright = false;
	if (key == RIGHT_KEY)
		player->keys.right = false;
	if (key == LEFT_KEY)
		player->keys.left = false;
	return (0);
}
