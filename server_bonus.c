/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:20:49 by ojimenez          #+#    #+#             */
/*   Updated: 2023/07/19 14:04:02 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

//SIGUSR2 = 0
//SIGUSR1 = 1

int	g_by[8];

void	ft_putnbr(int num)
{
	char	c;

	if (num > 9)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num <= 9)
	{
		c = num + '0';
		write(1, &c, 1);
	}
}

void	print_byte(void)
{
	int	res;

	res = g_by[0] * 128 + g_by[1] * 64 + g_by[2] * 32
		+ g_by[3] * 16 + g_by[4] * 8 + g_by[5] * 4 + g_by[6] * 2 + g_by[7];
	write(1, &res, 1);
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
	int					pid;

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = recieve_signal;
	write(1, "Servidor iniciado!!\n", 20);
	pid = getpid();
	write(1, "El PID del servidor es: ", 24);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR2, &s, 0);
		sigaction(SIGUSR1, &s, 0);
		pause();
	}
	return (0);
}
