/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:11:41 by nisauvig          #+#    #+#             */
/*   Updated: 2019/11/07 22:54:39 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aoti(char *str, int nb, int size)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		str[0] = '-';
		i++;
		nb = -nb;
	}
	while (nb / size >= 10)
		size *= 10;
	while (size > 0)
	{
		str[i] = (nb / size) + '0';
		nb %= size;
		size /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	len(int nb)
{
	int	i;
	int	nbr;

	i = 0;
	if (nb < 0)
	{
		nbr = -nb;
		i++;
	}
	else
		nbr = nb;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * (len(n) + 1))))
		return (NULL);
	str = aoti(str, n, 1);
	return (str);
}
