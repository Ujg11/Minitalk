/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:10:18 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/05 10:14:42 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
    char str[50] = "sdfghjklvxbzgz vcbbzj jbhh d j";
    printf("\nAbans: %s\n", str);
    ft_memset(str + 13, '.', 8*sizeof(char));
    printf("Despres:  %s", str);
    return 0;
}*/
