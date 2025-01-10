/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:11:49 by muokcan           #+#    #+#             */
/*   Updated: 2024/11/25 15:11:49 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>

static int	detect(char c, va_list args)
{
	if (c == '%')
		return (print_str("%"));
	else if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_str(va_arg(args, char *)));
	else if (c == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsignedint(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (print_hex(va_arg(args, unsigned int), c));
	return (-1);
}

static int	ft_print(char *str, va_list args)
{
	int	result;
	int	temp;

	result = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			temp = detect(*str, args);
			if (temp == -1)
				return (-1);
			result += temp;
		}
		else
			result += print_char(*str);
		str++;
	}
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		res;

	if (!str)
		return (-1);
	va_start(args, str);
	res = ft_print((char *)str, args);
	va_end(args);
	return (res);
}
