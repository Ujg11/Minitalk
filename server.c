/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:41:03 by ojimenez          #+#    #+#             */
/*   Updated: 2023/07/15 16:52:59 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

//SIGUSR2 = 0
//SIGUSR1 = 1

int	byte[8];

void	print_byte(void)
{
	int res;

	res = byte[0] * 128 + byte[1] * 64 + byte[2] * 32
	 + byte[3] * 16 + byte[4] * 8 + byte[5] * 4 + byte[6] * 2 + byte[7];
	ft_putnbr_fd(res, 1);
}

void	recieve_signal(int signal)
{
	static int	i = 0;

	if (signal == SIGUSR1)
	{
		byte[i] = 1;
		i++;
	}
	if (signal == SIGUSR2)
	{
		byte[i] = 0;
		i++;
	}
	if (i == 7)
	{
		print_byte();
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Servidor iniciado!!\n");
	ft_printf("El PID del servidor es: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, recieve_signal);
		signal(SIGUSR1, recieve_signal);
		pause();
	}
	return (0);
}
