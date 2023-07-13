/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:28:39 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/30 15:21:41 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_decimal(int n)
{
	char	*str;
	int		i;
	int		num_char;

	i = 0;
	num_char = 0;
	str = ft_itoa(n);
	if (!str)
		return (-1);
	num_char = ft_printf_string(str);
	if (num_char == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (num_char);
}
