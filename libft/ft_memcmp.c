/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:56:03 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/11 18:05:42 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)ptr1;
	s2 = (unsigned char *)ptr2;
	while (i < num)
	{
		if (s1[i] != s2[i])
			return ((int)s1[i] - (int)s2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
    char ptr1[] = "Holaafhgvjhb";
    char ptr2[] = "Holac";
    int res;

    res = ft_memcmp(ptr1, ptr2, 10);
    printf("Resultat = %d", res);
    return (0);
}*/
