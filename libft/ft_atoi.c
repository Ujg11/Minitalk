/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:28 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/11 18:09:46 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
/*
int main(void)
{
    char c[] = " \f\n\r\t\v +34561";
    int res;

    res = atoi(c);
    printf("Resultat atoi= %d\n", res);
    res = ft_atoi(c);
    printf("Resultat ft_atoi= %d\n", res);
    return (0);
}*/
