/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 06:00:45 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/16 06:01:39 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	int a;

	if (nb != -2147483648)
	{
		if (nb < 0)
		{
			write(fd, "-", 1);
			nb *= -1;
		}
		a = (nb % 10) + '0';
		if ((nb / 10) != 0)
			ft_putnbr_fd(nb / 10, fd);
		write(fd, &a, 1);
	}
	else
	{
		write(fd, "-2147483648", 11);
	}
}
