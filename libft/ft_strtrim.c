/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:31:13 by nisauvig          #+#    #+#             */
/*   Updated: 2019/11/15 16:53:37 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_test(char s, char const *ss)
{
	size_t	d;

	d = 0;
	while (ss[d] && s != ss[d])
		d++;
	if (!ss[d])
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ret;

	if (!s1)
		return (NULL);
	len = 0;
	j = ft_strlen(s1) - 1;
	i = 0;
	while (ft_test(s1[i], set))
		i++;
	while (j > 0 && ft_test(s1[j], set))
		j--;
	if ((int)(j - i + 1) > 0)
		len = j - i + 1;
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	ret = ft_memcpy(ret, s1 + i, len + 1);
	ret[len] = '\0';
	return (ret);
}
