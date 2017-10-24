/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:18:16 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/22 17:17:43 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	tmp = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = f(lst);
		list = list->next;
	}
	return (tmp);
}
