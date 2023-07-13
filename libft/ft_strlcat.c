/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:38:49 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/10 15:49:39 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	j = dst_len;
	if (size == 0)
		return (src_len);
	while (j < size - 1 && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	if (dst_len <= size)
		return (src_len + dst_len);
	else
		return (src_len + size);
}
/*
int main (void)
{
    char src[] = "Hola que tal va, ";
    char dst[50] = "tot be?";
    size_t llargada;

    llargada = ft_strlcat(src, dst, 30);
    printf("Cadena de origen: %s\nCadena de destino: %s\n", src, dst);
    printf("Llargada %d\n\n", llargada);
    return (0);
}*/
