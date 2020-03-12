/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:52:37 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/23 06:12:41 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*r;
	size_t	i;

	i = 0;
	if (!(r = malloc(size)))
		return (NULL);
	while (i < size)
	{
		r[i] = 0;
		i++;
	}
	return (r);
}
