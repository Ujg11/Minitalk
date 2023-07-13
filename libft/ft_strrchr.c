/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:48:09 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/11 19:09:07 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
/*
int main() {
    char str[] = "teste";
    char *ptr = ft_strrchr(str, 't');
    
    if (ptr != NULL) {
        printf("El caracter 'a' fue encontrado en la 
		posicion %ld de la cadena: %s\n", ptr - str, str);
    } else {
        printf("El caracter 'a' no fue encontrado en la cadena: %s\n", str);
    }
	printf("Cadena retornada: %s", ptr);
    return 0;
}*/
