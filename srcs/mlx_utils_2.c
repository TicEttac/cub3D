#include "cub3D.h"

int		load_texture(t_char *player)
{
	if (!(load_north(player)))
		return (BAD_OUT);
	if (!(load_south(player)))
		return (BAD_OUT);
	if (!(load_east(player)))
		return (BAD_OUT);
	if (!(load_west(player)))
		return (BAD_OUT);
	if (!(load_sprite(player)))
		return (BAD_OUT);
	return (GOOD_OUT);
}
