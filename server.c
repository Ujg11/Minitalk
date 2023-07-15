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



void	recieve_signal(int signal)
{
	char	*byte;
	int		i;

	i = 0;
	if (signal == SIGUSR2)
	
}


int	main(void)
{
	ft_printf("Servidor iniciado!!\n");
	ft_printf("El PID del servidor es: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, );
		signal(SIGUSR1, );
		pause();
	}
	return (0);
}
