/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:40:44 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/16 13:50:34 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	fin;

	fin = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	fin = ft_strlen(s + start);
	if (fin < len)
		len = fin;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int main(void)
{
	const char s[] = "Hola que tal va";
	char *subcadena;
	unsigned int start = 5;
	size_t len = 6;

	subcadena = ft_substr(s, start, len);
	printf("Cadena principal: %s\n", s);
	printf("Subcadena: %s\n", subcadena);
	return (0);
}*/
