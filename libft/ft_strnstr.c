/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 02:34:30 by nisauvig          #+#    #+#             */
/*   Updated: 2019/11/07 01:49:28 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!*n))
		return ((char *)h);
	while (h[i] && i < l)
	{
		j = 0;
		while (h[i + j] == n[j] && n[j] && (j + i) < l)
			j++;
		if (!n[j] && j <= l)
			return ((char *)&h[i]);
		i++;
	}
	return (NULL);
}
