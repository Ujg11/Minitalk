/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:14:16 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/30 15:22:57 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_string(char *str)
{
	int	num_char;

	if (str == NULL)
		str = "(null)";
	num_char = write(1, str, ft_strlen(str));
	if (num_char < 0)
		return (-1);
	return (num_char);
}
/*
int main(void)
{
	char str[] = "Hola que tal";
	int res;

	res = ft_printf_string(str);
	printf("\nRes ft = %d\n", res);
	res = printf("%s", str);
	printf("\nRes real = %d", res);
	return (0);
}*/
