#include "cub3D.h"

int		ft_parse_map(char **conf_file, int size, int index, t_map *file)
{
	int		i;
	int		i_map;
	int		start[2];

	i = 0;
	i_map = 0;
	start[0] = 0;
	start[1] = 0;
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
		if (!(file->map[i_map] = malloc(sizeof(t_tile) * ft_strlen(conf_file[index]))))
		{
			free_dtab(conf_file, size);
			return (error_flag("Malloc error.\n"));
		}
		i = 0;
		while (conf_file[index][i] != '\0')
		{
			if (ft_strchr("NSWE2T ", (int)conf_file[index][i]))
			{
				if (ft_strchr("NSWE", (int)conf_file[index][i]))
				{
					if (start[0] != 0)
						return (error_flag("Multiple entry points.\n"));
					start[0] = i_map;
					start[1] = i;
				}
				file->map[i_map][i].tile = '0';
				file->map[i_map][i].content = conf_file[index][i];
			}
			else if (ft_strchr("10", (int)conf_file[index][i]))
			{
				file->map[i_map][i].tile = conf_file[index][i];
				file->map[i_map][i].content = '0';
			}
			else
			{
				free_dtab(conf_file, size);
				return (error_flag("Erroneous map.\n"));
			}
			i++;
		}
		file->map[i_map][i].tile = '\0';
		file->map[i_map][i].content = '\0';
		index++;
		i_map++;
	}
	free_dtab(conf_file, size - 1);
	if (!(file->map[i_map] = malloc(sizeof(t_tile))))
		return (error_flag("Malloc error.\n"));
	file->map[i_map][0].tile = '\0';
	file->map[i_map][0].content = '\0';
	return (map_checking(file->map, start[0], start[1]));
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

void	print_map(t_tile **map)
{
	int x = 0;
	int y;

	while (map[x][0].tile != '\0'){
		y = 0;
		while (map[x][y].tile != '\0'){
			printf("%c", map[x][y].tile);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("\n");
}

/*int		map_checking(t_tile **map, int x, int y)
{
	char		card[4];
	int		next_x;
	int		next_y;
	size_t		i;

	i = 0;
	if (x <= 0 || y <= 0 || map[x][y + 1].tile == '\0' || map[x + 1][0].tile == '\0')
		return (error_flag("Open map.\n"));
	map[x][y].tile = ' ';
	card[0] = map[x - 1][y].tile;
	card[1] = map[x + 1][y].tile;
	card[2] = map[x][y - 1].tile;
	card[3] = map[x][y + 1].tile;
	while (i < 4)
	{
		if (!ft_strchr("01 ", card[i]))
		{
			return (error_flag("Erroneous map.\n"));
		}
		if (card[i] == '0')
		{
			i == 0 ? next_x = x - 1 : 0;
			i == 1 ? next_x = x + 1 : 0;
			i == 2 ? next_y = y - 1 : 0;
			i == 3 ? next_y = y + 1 : 0;
			next_x == x - 1 || next_x == x + 1 ? next_y = y : 0;
			next_y == y - 1 || next_y == y + 1 ? next_x = x : 0;
			print_map(map);
			if (!map_checking(map, next_x, next_y))
				return (BAD_OUT);
		}
		i++;
	}
	return (GOOD_OUT);
}*/

