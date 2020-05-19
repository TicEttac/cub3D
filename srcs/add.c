#include "cub3D.h"

int		add_win(char *line, t_map *file, char *id)
{
	int		i;
	char	axis_switch;

	(void)id;
	i = 0;
	axis_switch = 0;
	while (ft_strchr(" \tR", line[i]))
		i++;
	while (line[i] && axis_switch <= 1)
	{
		if ((line[i] > '9' || line[i] < '0') && !ft_strchr(" \t", line[i]))
			return (error_flag("Window size error.\n"));
		if (line[i] == ' ' ||line[i] == '\t')
		{
			axis_switch++;
			while (ft_strchr(" \t", line[i]))
				i++;
		}
		else
			file->win[axis_switch] = (file->win[axis_switch] * 10) + line[i] - 48;
		i++;
	}
	return (GOOD_OUT);
}

char	*add_path(char *line, char *id)
{
	int		i;

	i = 0;
	while ((ft_strchr(id, line[i]) || line[i] == ' '))
		i++;
	return (line + i);
}

int		add_floor(char *line, t_map *file, char *id)
{
	int		i;
	char	swich;

	(void)id;
	i = 0;
	swich = 0;
	while (line[i] == 'F' || line[i] == ' ')
		i++;
	while (line[i] && swich <= 2)
	{
		if (!(ft_memchr("0123456789 ,", line[i], 12)))
			return (error_flag("Floor color error.\n"));
		if (line[i] == ' ' || line[i] == ',')
			swich++;
		else
			file->f_color[swich] = (file->f_color[swich] * 10) + line[i] - 48;
		i++;
	}
	return (GOOD_OUT);
}

int		add_ceiling(char *line, t_map *file, char *id)
{
	int		i;
	char	swich;

	(void)id;
	i = 0;
	swich = 0;
	while (line[i] == 'C' || line[i] == ' ')
		i++;
	while (line[i] && swich <= 2)
	{
		if (!(ft_memchr("0123456789 ,", line[i], 12)))
			return (error_flag("Ceiling color error.\n"));
		if (line[i] == ' ' || line[i] == ',')
			swich++;
		else
			file->c_color[swich] = file->c_color[swich] * 10 + (line[i] - 48);
		i++;
	}
	return (GOOD_OUT);
}

void	set_struct(t_map *file)
{
	ft_bzero(file->win, 2);
	file->f_color[0] = 0;
	file->f_color[1] = 0;
	file->f_color[2] = 0;
	file->c_color[0] = 0;
	file->c_color[1] = 0;
	file->c_color[2] = 0;
	file->n_path = 0;
	file->so_path = 0;
	file->we_path = 0;
	file->ea_path = 0;
	file->sp_path = 0;
}
