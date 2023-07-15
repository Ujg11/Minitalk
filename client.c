/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:41:21 by ojimenez          #+#    #+#             */
/*   Updated: 2023/07/15 16:32:16 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

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
			err = kill(pid, SIGUSR1);
			if (err == -1)
				print_error();
		}
		else
		{
			err = kill(pid, SIGUSR2);
			if (err == -1)
				print_error();
		}
		n_bit++;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0)
			return (1);
		str = argv[2];
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
