/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:23:13 by nisauvig          #+#    #+#             */
/*   Updated: 2019/11/13 16:19:20 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dafinish;
	const char	*dasource;

	dafinish = dest;
	dasource = src;
	if (n != 0 && dest != src)
	{
		i = 0;
		while (i < n)
		{
			dafinish[i] = dasource[i];
			i++;
		}
	}
	return (dest);
}
