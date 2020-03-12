/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:19:02 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/16 04:07:54 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dadest;
	unsigned char	*dasource;

	i = 0;
	dasource = (unsigned char *)src;
	dadest = (unsigned char *)dst;
	while (n--)
	{
		dadest[i] = dasource[i];
		if (dadest[i] == (unsigned char)c)
		{
			i++;
			return (&dadest[i]);
		}
		i++;
	}
	return (NULL);
}
