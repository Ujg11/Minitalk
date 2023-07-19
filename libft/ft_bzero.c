/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:15:12 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/05 10:18:43 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = 0;
		i++;
	}
}
/*
int main(void)
{
    char str[100] = "Hola que tal estas, com va totghgjhzwaxescrvtf";

    printf("\nAbans: %s\n", str);
    ft_bzero(str + 13, 4);
    printf("Despres:  %s\n", str);
    return 0;
}*/
