/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:49:45 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/10 11:50:12 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main(void)
{
    char str1[] = "Hola mundo";
    char str2[] = "Hola amigos";
    int result;

    result = ft_strncmp(str1, str2, 7);
    if (result == 0) {
        printf("Las primeras 4 letras de str1 y str2 son iguales.\n");
    } else if (result < 0) {
        printf("Las primeras 4 letras de str1 son menores que las de str2.\n");
    } else {
        printf("Las primeras 4 letras de str1 son mayores que las de str2.\n");
    }
    return 0;
}*/
