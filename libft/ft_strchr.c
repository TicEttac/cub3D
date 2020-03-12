/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:55:05 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/24 18:21:11 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		while (*s)
		{
			s++;
			if (*s == (char)c)
				return ((char *)s);
		}
	}
	return (NULL);
}
