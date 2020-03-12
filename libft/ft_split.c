/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:57:33 by nisauvig          #+#    #+#             */
/*   Updated: 2019/11/13 19:53:02 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			res++;
		while (s[i] != c && s[i])
			i++;
	}
	return (res);
}

static char		*ft_strdupi(const char *src, size_t szword)
{
	char	*ret;
	size_t	i;

	if (!(ret = malloc(szword + 1)))
		return (NULL);
	i = 0;
	while (src[i] && i < szword)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char		**ft_fillword(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	iword;
	size_t	tmp;

	i = 0;
	iword = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			tmp = 0;
			while (s[i + tmp] != c && s[i + tmp])
				tmp++;
			tab[iword] = ft_strdupi((char *)(s + i), tmp);
			iword++;
			i += tmp;
		}
		else
			i++;
	}
	tab[iword] = NULL;
	return (tab);
}

char			**ft_split(char const *s1, char c)
{
	size_t	nbword;
	char	**tab;

	if (!s1)
		return (NULL);
	nbword = ft_countword(s1, c);
	if (!(tab = malloc(sizeof(char *) * (nbword + 1))))
		return (NULL);
	tab = ft_fillword(s1, c, tab);
	return (tab);
}
