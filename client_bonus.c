/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:20:39 by ojimenez          #+#    #+#             */
/*   Updated: 2023/07/19 12:09:39 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void	ft_ack(int signal, siginfo_t *info, void *v)
{
	static int	i = 0;

	write(2, "ack", 3);
	(void)info;
	(void)v;
	if (signal == SIGUSR1)
		ft_printf("chek akc%i recieved\n", i);
	i = (i + 1) % 8;
}

void	print_error(void)
{
	ft_printf("Error al enviar bit del client al server\n");
	exit(EXIT_FAILURE);
}

void	send_signal(int pid, char c)
{
	int		n_bit;
	int		err;

	err = 1;
	n_bit = 7;
	while (n_bit >= 0)
	{
		if ((c >> n_bit) & 1)
		{
			if (kill(pid, SIGUSR1) > 0)
				print_error();
			pause();
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				print_error();
			pause();
		}
		n_bit--;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	char				*str;
	int					i;
	struct sigaction	s;

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = ft_ack;
	if (argc == 3)
	{
		i = 0;
		str = argv[2];
		pid = ft_atoi(argv[1]);
		sigaction(SIGUSR1, &s, 0);
		while (str[i])
		{
			send_signal(pid, str[i]);
			i++;
		}
	}
	else
	{
		ft_printf("\nError al recibir los parametros\n");
		ft_printf("Se espera: <Server pid> <Message>\n");
	}
	return (0);
}
