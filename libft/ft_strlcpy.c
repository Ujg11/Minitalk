/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:37:04 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/10 15:31:26 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (n == 0)
		return (len);
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
/*
int main(void) {
    char src[] = "Hola mundo!";
    char dest[10];
    size_t n = sizeof(dest);

    size_t len = ft_strlcpy(dest, src, n);
    printf("Cadena de origen: %s\nCadena de destino: %s\n", src, dest);
    printf("Tamaño de cadena de origen: %zu\n", strlen(src));
    printf("Tamaño de cadena de destino: %zu\n", strlen(dest));
    printf("Longitud devuelta: %zu\n", len);
    return 0;
}*/
