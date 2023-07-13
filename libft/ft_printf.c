/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:51:40 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/30 15:23:14 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	conversions(char c, va_list args)
{
	int	num_char;

	num_char = 0;
	if (c == 'c')
		num_char = ft_printf_char(va_arg(args, int));
	else if (c == 's')
		num_char = ft_printf_string(va_arg(args, char *));
	else if (c == 'p')
		num_char = ft_printf_puntero(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		num_char = ft_printf_decimal(va_arg(args, int));
	else if (c == 'u')
		num_char = ft_printf_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		num_char = ft_printf_hexa_min(va_arg(args, unsigned int));
	else if (c == 'X')
		num_char = ft_printf_hexa_maj(va_arg(args, unsigned int));
	else if (c == '%')
	{
		num_char += write(1, "%", 1);
	}
	else
		return (-1);
	return (num_char);
}

static int	start_printf(char *str, va_list args, int num_char)
{
	int	i;
	int	aux;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			aux = conversions(str[i + 1], args);
			if (aux == -1)
				return (-1);
			num_char = num_char + aux;
			i++;
		}
		else
		{
			aux = ft_printf_char(str[i]);
			if (aux == -1)
				return (-1);
			num_char = num_char + aux;
		}
		i++;
	}
	return (num_char);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		num_char;
	char	*s;

	s = (char *)str;
	num_char = 0;
	va_start(args, str);
	num_char = start_printf(s, args, num_char);
	va_end(args);
	return (num_char);
}
