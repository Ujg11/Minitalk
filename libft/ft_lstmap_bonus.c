/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:22:44 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/19 15:58:53 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first;
	t_list	*l;

	if (!lst)
		return (NULL);
	new_lst = 0;
	while (lst)
	{
		l = f(lst->content);
		first = ft_lstnew(l);
		if (!first)
		{
			del(l);
			ft_lstclear(&new_lst, del);
		}
		ft_lstadd_back(&new_lst, first);
		lst = lst->next;
	}
	return (new_lst);
}
