/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:49:53 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/16 11:21:34 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	copy = (char *)malloc(len * sizeof(char));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*Aqui al strlen li sumem +1 per tenir tb el '\0'
 Despres de fer el copiar a l'ultim copia[i] = '\0'*/
/*
int main(void)
{
	const char *s1 = "sadf\nvbf";
	char *copia;

	copia = ft_strdup(s1);
	printf("Original: %s\n", s1);
	printf("Copia: %s\n", copia);
	free(copia);
	return (0);
}*/
