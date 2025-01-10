/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xXP.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:12:07 by muokcan           #+#    #+#             */
/*   Updated: 2024/11/25 15:12:07 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/ft_printf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	print_hex(unsigned int d, char c)
{
	int		digit;
	int		temp;

	digit = 0;
	if (d == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (d >= 16)
		digit += print_hex(d / 16, c);
	temp = d % 16;
	if (temp < 10)
		ft_putchar(temp + '0');
	else
	{
		if (c == 'x')
			ft_putchar(temp - 10 + 'a');
		else if (c == 'X')
			ft_putchar(temp - 10 + 'A');
	}
	return (digit + 1);
}

int	ptr_hex(unsigned long d)
{
	int		digit;
	int		temp;

	digit = 0;
	if (d == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (d >= 16)
		digit += ptr_hex(d / 16);
	temp = d % 16;
	if (temp < 10)
		ft_putchar(temp + '0');
	else
		ft_putchar(temp - 10 + 'a');
	return (digit + 1);
}

int	print_ptr(void *p)
{
	if (!p)
	{
		print_str("(nil)");
		return (5);
	}
	ft_putchar('0');
	ft_putchar('x');
	return (ptr_hex((unsigned long)p) + 2);
}
