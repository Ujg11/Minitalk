/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:21 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/10 11:43:25 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	min;

	if (c >= 65 && c <= 90)
	{
		min = c + 32;
		return (min);
	}
	else
		return (c);
}
/*
int main(void)
{
    char c = 'P';
    char c_min;

    c_min = ft_tolower(c);
    printf("La lletra %c en minuscula es: %c\n", c, c_min);
    return (0);
}*/
