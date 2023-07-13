/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:33:15 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/19 13:01:17 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_char(int n, int fd)
{
	char	character;

	character = n + '0';
	write (fd, &character, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	rest;
	size_t	module;

	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		module = n % 10;
		rest = n / 10;
		if (rest > 0)
			ft_putnbr_fd (rest, fd);
		write_char (module, fd);
	}
}
/*
int main(void)
{
	int n  = 2147483647;
	int fd = 1;

	ft_putnbr_fd(n, fd);
	return (0);
}*/
