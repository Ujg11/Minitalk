/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:29:24 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/11 18:52:37 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	if (len == 0)
		return (NULL);
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] && i + j < len
			&& needle[j] == haystack[i + j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char haystack[] = "dadala";
    char needle[] = "ada";
    char *resultat;

    resultat = ft_strnstr(haystack, needle, 5);
    printf("Resultat = %s\n", resultat);
    resultat = strstr(haystack, needle);
    printf("Resultat funcio original = %s\n", resultat);
    return (0);
}*/
