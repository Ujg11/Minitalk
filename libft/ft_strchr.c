/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:49 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/11 16:01:33 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
/*
int main() {
    char str[] = "Hola, mundo!";
    char *ptr = ft_strchr(str, ' ');
    if (ptr != NULL) {
        printf("El caracter 'm' fue encontrado en la
	   	posicion %ld de la cadena: %s\n",ptr - str, str);
    } else {
        printf("El caracter 'm' no fue encontrado en la cadena: %s\n", str);
    }
    return 0;
}*/
