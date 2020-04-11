/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:02:46 by nisauvig          #+#    #+#             */
/*   Updated: 2020/03/12 17:54:15 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int		parser(char *path_to_conf, t_map *file)
{
	int				map_fd;
	int				line_n;
	char			*line;
	int				gnl;
	char			**conf_file;

	conf_file = NULL;
	line = NULL;
	if (!(map_fd = open(path_to_conf, O_RDONLY)))
		return (error_flag("Wrong path to configuration file.\n"));
	line_n = 0;
	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(map_fd, &line);
		if (!(conf_file = one_more_line(conf_file, line, line_n)))
		{
			free_dtab(conf_file, line_n);
			return (error_flag("Malloc error.\n"));
		}
		line_n++;
	}
	set_struct(file);
	return (ft_parse_infos(conf_file, line_n, file));
}

void	free_dtab(char **dtab, int size)
{
	while (size)
	{
		free(dtab[size]);
		dtab[size] = NULL;
		size--;
	}
	free(dtab);
	dtab = NULL;
}

int		error_flag(char *verbosity)
{
	ft_putstr("Error\n");
	ft_putstr(verbosity);
	return (BAD_OUT);
}

char	**one_more_line(char **tab, char *to_add, int index)
{
	int				i;
	char			**return_tab;

	i = 0;
	if (!(return_tab = malloc(sizeof(char*) * (index + 1))))
		return (NULL);
	while (i < index)
	{
		if (!(return_tab[i] = ft_strdup(tab[i])))
			return (NULL);
		i++;
	}
	return_tab[i] = ft_strdup(to_add);
	if (index)
		free_dtab(tab, index - 1);
	free(to_add);
	return (return_tab);
}

int		ft_parse_infos(char **conf_file, int size, t_map *file)
{
	static t_parse	c[] = {{"R ", &add_win}, {"NO", &add_north},
	{"SO", &add_south}, {"WE", &add_west}, {"EA", &add_east},
	{"S ", &add_sprite}, {"F ",&add_floor}, {"C ", &add_ceiling}};
	int				i;
	int				j;
	int				ret;

	i = 0;
	while (i < size && !(ft_fullfilled(file)))
	{
		j = 0;
		while (j < 8 && (ft_memcmp(c[j].id, conf_file[i], 2)))
			j++;
		if (!(ft_memcmp(c[j].id, conf_file[i], 2)))
			if (c[j].func(conf_file[i], file, c[j].id) == BAD_OUT)
			{
				free_dtab(conf_file, size - 1);
				return (BAD_OUT);
			}
		i++;
	}
	return (ft_parse_map(conf_file, size, file));
}
