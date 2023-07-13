/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:48:42 by ojimenez          #+#    #+#             */
/*   Updated: 2023/05/26 12:55:03 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printf_char(char c);
int	ft_printf_string(char *str);
int	ft_printf_puntero(void *p);
int	ft_printf_hexa(unsigned int l, int num_char, char *base);
int	ft_printf_decimal(int n);
int	ft_printf_unsigned(unsigned int n);
int	ft_printf_hexa_min(unsigned int n);
int	ft_printf_hexa_maj(unsigned int n);
int	ft_printf_hexa_long(unsigned long l, int num_char, char *base);

#endif
