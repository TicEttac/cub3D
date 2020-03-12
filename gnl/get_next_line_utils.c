/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 08:01:46 by nisauvig          #+#    #+#             */
/*   Updated: 2020/03/12 17:45:37 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen_pimp(char *s, int r)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	if (r == 1)
		while (s[i] && s[i] != '\n')
			i++;
	else
		while (s[i])
			i++;
	return (i);
}

char	*ft_strcat_gnl(char *s1, char *s2)
{
	int	i;
	int	dlen;

	i = 0;
	dlen = ft_strlen_pimp(s1, 1);
	while (s2[i] && s2[i] != '\n')
	{
		s1[dlen + i] = s2[i];
		i++;
	}
	s1[dlen + i] = '\0';
	return (s1);
}

char	*ft_strjoin_pimp(char *s1, char *s2)
{
	char	*s3;
	size_t	c;

	c = 0;
	if (!s2)
		return (NULL);
	c = ft_strlen_pimp(s2, 1);
	if (s1)
		c += ft_strlen_pimp(s1, 1);
	if (!(s3 = malloc(sizeof(char) * (c + 1))))
		return (NULL);
	s3[0] = '\0';
	if (s1)
	{
		ft_memcpy(s3, s1, ft_strlen_pimp(s1, 1) + 1);
		ft_strcat_gnl(s3, s2);
	}
	else
		ft_memcpy(s3, s2, ft_strlen_pimp(s2, 1) + 1);
	return (s3);
}

char	*ft_strdupimp(char *src, int r)
{
	char	*duh;
	size_t	i;

	if (!src || !(duh = malloc(ft_strlen_pimp(src, r) + 1)))
		return (NULL);
	i = 0;
	if (r == 1)
		while (src[i] && src[i] != '\n')
		{
			duh[i] = src[i];
			i++;
		}
	else
		while (src[i])
		{
			duh[i] = src[i];
			i++;
		}
	duh[i] = '\0';
	return (duh);
}
