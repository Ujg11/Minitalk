/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:40:44 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/16 15:25:37 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ini;
	size_t	end;
	char	*res;

	ini = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[ini] && ft_strchr(set, s1[ini]))
		ini++;
	while (end > ini && ft_strchr(set, s1[end - 1]))
		end--;
	res = ft_substr(s1, ini, end - ini);
	if (!res)
		return (NULL);
	return (res);
}

/*
int main(void)
{
	char const s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char const set[] = "lt";
	char *res;

	res = ft_strtrim(s1, set);
	printf("Cadena original: %s\n", s1);
	printf("Cadena retallada: %s\n", res);
	return (0);
}*/
