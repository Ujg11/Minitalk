/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:20:49 by ojimenez          #+#    #+#             */
/*   Updated: 2023/07/18 19:41:47 by ojimenez         ###   ########.fr       */
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

void	recieve_signal(int signal, siginfo_t *info, void *v)
{
	static int	i = 0;

	(void)v;
	if (signal == SIGUSR1)
	{
		g_by[i] = 1;
		kill(info->si_pid, SIGUSR1);
		i++;
	}
	if (signal == SIGUSR2)
	{
		g_by[i] = 0;
		kill(info->si_pid, SIGUSR1);
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
	struct sigaction	s;

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = recieve_signal;
	ft_printf("Servidor iniciado!!\n");
	ft_printf("El PID del servidor es: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR2, &s, 0);
		sigaction(SIGUSR1, &s, 0);
		pause();
	}
	return (0);
}
