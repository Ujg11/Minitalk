/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:28:59 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/30 15:22:37 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

static int	write_hexa(int i, int v[], char *base)
{
	int	num_char;
	int	pos;
	int	aux;

	num_char = 0;
	if (v[i] == 0)
		i--;
	while (i >= 0)
	{
		pos = v[i];
		aux = write(1, &base[pos], 1);
		if (aux == -1)
			return (-1);
		num_char++;
		i--;
	}
	return (num_char);
}

static int	littlenum(unsigned long l, char *base)
{
	int	num_char;

	num_char = write(1, &base[l], 1);
	if (num_char == -1)
		return (-1);
	return (num_char);
}

int	ft_printf_hexa(unsigned int l, int num_char, char *base)
{
	unsigned int	mod;
	int				v[16];
	int				i;

	i = 0;
	if (l < 16)
		return (littlenum(l, base));
	while (i < 16)
		v[i++] = -1;
	i = 0;
	mod = l % 16;
	l = l / 16;
	while (l >= 15)
	{
		v[i] = mod;
		mod = l % 16;
		l = l / 16;
		i++;
	}
	v[i + 1] = l;
	v[i++] = mod;
	num_char = write_hexa(i, v, base);
	if (num_char == -1)
		return (-1);
	return (num_char);
}
/*
int	main(void)
{
	int	i;
	int num = -10;

	i = ft_printf_hexa(num, 0, "0123456789abcdef");
	printf("\n%d", i);
	i = printf("\nOriginal retorna: %x", num);
	printf("\n%d", i);
	return (0);
}*/