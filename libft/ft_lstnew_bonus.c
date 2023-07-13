/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:55:33 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/17 20:55:33 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int main(void)
{
	int	num = 42;
	int *contingut;
	t_list	*node;

	node = ft_lstnew(&num);
	if (node != NULL)
	{
		contingut = (int *)node->content;
		printf("Contingut de node->content: %d\n", *contingut);
	}
	free(node);
	return (0);
}*/