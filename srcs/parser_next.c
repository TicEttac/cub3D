
#include "../includes/cub3D.h"

int		ft_parse_map(char **conf_file, int size, t_map *file)
{
	return (GOOD_OUT);
}

int		ft_fullfilled(t_map *file)
{
	if (!(file->win[0] && file->win[1]))
		return (0);
	if (!(file->f_color[0] || file->f_color[1] || file->f_color[2]))
		return (0);
	if (!(file->c_color[0] || file->c_color[1] || file->c_color[2]))
		return (0);
	if (!file->n_path)
		return (0);
	if (!file->so_path)
		return (0);
	if (!file->ea_path)
		return (0);
	if (!file->we_path)
		return (0);
	if (!file->sp_path)
		return (0);
	return (1);
}
