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

int		parser(char *path_to_conf)
{
	int		map_fd;
	int		line_n;
	int		gnl_ret;
	char	*line;
	char	**conf_file;

	conf_file = NULL;
	line = NULL;
	if (!(map_fd = open(path_to_conf, O_RDONLY)))
		return (error_flag("Wrong path to configuration file.\n"));
	line_n = 0;
	gnl_ret = 1;
	while (gnl_ret)
	{
		gnl_ret = get_next_line(map_fd, &line);
		if (!(conf_file[line_n] = ft_strdup(line)))
		{
			free_dtab(conf_file, line_n);
			return (error_flag("Malloc error.\n"));
		}
		line_n++;
		free(line);
	}
	return (ft_parse_map(conf_file) == BAD_OUTPUT ? BAD_OUTPUT : GOOD_OUTPUT);
}

void	free_dtab(char **dtab, int size)
{
	while (size)
	{
		free(dtab[size]);
		size--;
	}
	free(dtab);
}

int		error_flag(char *verbosity)
{
	ft_putstr(verbosity);
	return (BAD_OUTPUT);
}

int main(int ac, char **av)
{
	parser(av[0]);
}
