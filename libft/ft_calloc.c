/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:13:16 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/11 19:48:21 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*bloque;
	size_t	i;

	i = count * size;
	bloque = malloc(count * size);
	if (!bloque)
		return (NULL);
	else
	{
		ft_bzero(bloque, count * size);
		return (bloque);
	}
}
/*
int main(void)
{
	int *b;
	int tamany = 5;
	int i;

	i = tamany * sizeof(int);
	b = (int *)calloc(tamany, sizeof(int));
	while (i > 0)
	{
		printf("%d ", b[i]);
		i--;
	}
	free(b);
	return (0);
}*/
