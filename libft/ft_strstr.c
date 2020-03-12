/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:58:49 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/16 02:34:50 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!*n) || h == n)
		return ((char *)h);
	while (h[i])
	{
		j = 0;
		while (h[i + j] == n[j] && n[j])
			j++;
		if (!n[j])
			return ((char *)&h[i]);
		i++;
	}
	return (NULL);
}
