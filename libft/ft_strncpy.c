/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 00:13:55 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/11 00:24:39 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ndst;
	char	*nsrc;

	ndst = dst;
	nsrc = (char *)src;
	while (len--)
	{
		if (*nsrc)
			*ndst++ = *nsrc++;
		else
			*ndst++ = '\0';
	}
	return (dst);
}
