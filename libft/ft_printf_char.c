/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:33:53 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/30 15:21:35 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_char(char c)
{
	int	num_char;

	num_char = write(1, &c, 1);
	if (num_char == -1)
		return (-1);
	return (num_char);
}
/*
int main(void)
{
	char c = 'H';
	int res;

	res = ft_printf_char(c);
	printf("\nRes ft = %d\n", res);
	res = printf("%c", c);
	printf("\nRes real = %d", res);
	return (0);
}*/