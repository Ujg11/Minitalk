/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:50:43 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/11 18:03:03 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)ptr;
	while (i < num)
	{
		if (str[i] == (unsigned char)value)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
/*
int main() {
    char str[] = "Hello, world!";
    char *ptr;
    
    ptr = (char*) ft_memchr(str, 'w', 13);
    if (ptr != NULL) {
        printf("El caracter 'w' fue encontrado en la 
		posicion %ld de la cadena: %s\n", ptr - str, str);
    } else {
        printf("El caracter 'w' no se ha encontrado en la cadena: %s\n", str);
    }
    return 0;
}*/
