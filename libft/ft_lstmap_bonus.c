/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 05:20:58 by nisauvig          #+#    #+#             */
/*   Updated: 2019/10/27 02:23:19 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (!f || !lst)
		return (NULL);
	if (!(res = ft_lstnew(f(lst->content))))
	{
		ft_lstdelone(res, del);
		return (res);
	}
	if (lst->next)
		res->next = ft_lstmap(lst->next, f, del);
	else
		res->next = NULL;
	return (res);
}
