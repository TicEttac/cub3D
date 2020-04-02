
#include "../includes/cub3D.h"

int		add_north(char *line, t_map *file, char *id)
{
	if (!(file->n_path = ft_strdup(add_path(line, id))))
		return (error_flag("North path malloc error.\n"));
	return (GOOD_OUT);
}

int		add_south(char *line, t_map *file, char *id)
{
	if (!(file->so_path = ft_strdup(add_path(line, id))))
		return (error_flag("South path malloc error.\n"));
	return (GOOD_OUT);
}

int		add_east(char *line, t_map *file, char *id)
{
	if (!(file->ea_path = ft_strdup(add_path(line, id))))
		return (error_flag("East path malloc error.\n"));
	return (GOOD_OUT);
}

int		add_west(char *line, t_map *file, char *id)
{
	if (!(file->we_path = ft_strdup(add_path(line, id))))
		return (error_flag("West path malloc error.\n"));
	return (GOOD_OUT);
}

int		add_sprite(char *line, t_map *file, char *id)
{
	if (!(file->sp_path = ft_strdup(add_path(line, id))))
		return (error_flag("Sprite path malloc error.\n"));
	return (GOOD_OUT);
}
