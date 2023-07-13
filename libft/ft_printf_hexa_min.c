/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:58:21 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/30 15:22:29 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_hexa_min(unsigned int n)
{
	int	num_char;

	num_char = ft_printf_hexa(n, 0, "0123456789abcdef");
	return (num_char);
}
