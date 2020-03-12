/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:35:16 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/16 00:35:26 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ndst;
	const char	*nsrc;

	ndst = dst;
	nsrc = src;
	if (ndst == nsrc)
		return (ndst);
	if (ndst < nsrc)
		while (len--)
			*ndst++ = *nsrc++;
	else
	{
		ndst += len - 1;
		nsrc += len - 1;
		while (len--)
			*ndst-- = *nsrc--;
	}
	return (dst);
}
