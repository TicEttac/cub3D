/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 05:03:29 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/28 22:17:09 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*d;

	if (!lst || !del)
		return ;
	l = *lst;
	while (l)
	{
		d = l->next;
		ft_lstdelone(l, *del);
		l = d;
	}
	*lst = NULL;
}
