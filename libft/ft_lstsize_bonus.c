/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 03:51:16 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/23 07:04:12 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*prt;
	int		r;

	if (!lst)
		return (0);
	prt = lst;
	r = 1;
	while (prt->next)
	{
		prt = prt->next;
		r++;
	}
	return (r);
}
