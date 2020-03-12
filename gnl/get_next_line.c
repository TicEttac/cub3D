/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 04:37:26 by nisauvig          #+#    #+#             */
/*   Updated: 2020/03/12 17:44:02 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		ft_bln(char *buf)
{
	int				i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_assign(char **end, char *buf, int i)
{
	char			*tmp;

	tmp = ft_strdupimp(buf, i);
	free(*end);
	*end = tmp;
	return (*end);
}

int		make_str(int fd, char **end, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;
	int				i;
	int				r;

	if ((i = ft_bln(*end)) >= 0 && (ft_assign(line, *end, 1) != NULL))
	{
		ft_assign(end, *end + i + 1, 0);
		return (1);
	}
	while (i < 0 && (r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = 0;
		i = ft_bln(buf);
		tmp = ft_strjoin_pimp(*end, buf);
		(*end) ? free(*end) : 0;
		*end = tmp;
	}
	tmp = ft_strdupimp(*end, 1);
	*line = (tmp != NULL) ? ft_assign(line, tmp, 0) : *line;
	free(tmp);
	if (buf + i + 1 && i >= 0)
		ft_assign(end, buf + i + 1, 0);
	return (r = (r > 0) ? 1 : r);
}

int		get_next_line(int fd, char **line)
{
	static	char	*end = NULL;
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char))))
		return (-1);
	(*line)[0] = '\0';
	if ((ret = make_str(fd, &end, line)) != 1)
	{
		free(end);
		end = NULL;
	}
	return (ret);
}
