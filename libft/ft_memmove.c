/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:55:03 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/10 15:23:29 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (!n || dest == src)
		return (dest);
	if (dest > src)
	{
		while (n--)
		{
			*((char *)dest + n) = *((char *)src + n);
		}
	}
	else
	{
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	return (dest);
}
/*
int main(void)
{
    char str1[] = "Hola que tal";
    char str2[] = "Com va la vida";
    size_t n = strlen(str2) + 1;

    printf("Abans memmove:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    ft_memmove(str1, str2, n);
    
    printf("\nDespres memmove:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    return (0);
}*/
