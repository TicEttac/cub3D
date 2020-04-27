
#include "../includes/cub3D.h"

int		ft_parse_map(char **conf_file, int size, int index, t_map *file)
{
	int		i;

	i = 0;
	while (conf_file[index][i] != '1' && conf_file[index][i] != '0')
	{
		if (index >= size)
		{
			free_dtab(conf_file, size);
			return (error_flag("No map in configuration file.\n"));
		}
		i = conf_file[index][i] == '\0' ? 0 : i + 1;
		i == 0 ? index++ : 0;
	}
	if (!(file->map = malloc(sizeof(t_tile *) * (size - index))))
	{
		free_dtab(conf_file, size);
		return (error_flag("Malloc error.\n"));
	}
	while (index < size)
	{
		if (!(file->map[index] = malloc(sizeof(t_tile) * ft_strlen(conf_file[index] + 1))))
		{
			free_dtab(conf_file, size);
			return (error_flag("Malloc error.\n"));
		}
		i = 0;
		while (conf_file[index][i] != '\0')
		{
			if (conf_file[index][i] != '0' && conf_file[index][i] != '1')
			{
				file->map[index][i].tile = '0';
				file->map[index][i].content = conf_file[index][i];
			}
			else
			{
				file->map[index][i].tile = conf_file[index][i];
				file->map[index][i].content = '0';
			}
			i++;
		}
		file->map[index][i].tile = '\0';
		file->map[index][i].content = '\0';
		index++;
	}
	free_dtab(conf_file, size - 1);
	if (!(file->map[index] = malloc(sizeof(t_tile))))
		return (error_flag("Malloc error.\n"));
	file->map[index][0].tile = '\0';
	file->map[index][0].content = '\0';
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
