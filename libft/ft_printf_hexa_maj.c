/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:18:32 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/30 15:22:17 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_hexa_maj(unsigned int n)
{
	int	num_char;

	num_char = ft_printf_hexa(n, 0, "0123456789ABCDEF");
	return (num_char);
}
