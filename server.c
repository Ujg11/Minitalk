/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:41:03 by ojimenez          #+#    #+#             */
/*   Updated: 2023/07/19 15:23:18 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

//SIGUSR2 = 0
//SIGUSR1 = 1

int	g_by[8];

void	print_byte(void)
{
	int	res;

	res = g_by[0] * 128 + g_by[1] * 64 + g_by[2] * 32
		+ g_by[3] * 16 + g_by[4] * 8 + g_by[5] * 4 + g_by[6] * 2 + g_by[7];
	ft_printf("%c", res);
}

void	recieve_signal(int signal)
{
	static int	i = 0;

	if (signal == SIGUSR1)
	{
		g_by[i] = 1;
		i++;
	}
	if (signal == SIGUSR2)
	{
		g_by[i] = 0;
		i++;
	}
	if (i == 8)
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
