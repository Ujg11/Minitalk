/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puntero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:47:36 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/30 15:22:47 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_puntero(void *p)
{
	unsigned long	l;
	int				num_char;
	int				aux;

	l = (unsigned long)p;
	num_char = 2;
	if (ft_printf_string("0x") == -1)
		return (-1);
	aux = ft_printf_hexa_long(l, 0, "0123456789abcdef");
	if (aux == -1)
		return (-1);
	num_char += aux;
	return (num_char);
}
/*
int main(void)
{
	int *p;
	int num = 2;
	int i = 20368;

	p = &num;
	printf("Num = %p\n", p);
	printf("Resultat = %x", i);
	return (0);
}*/
