/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:13:35 by muokcan           #+#    #+#             */
/*   Updated: 2024/11/26 18:20:35 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_str(char *c);
int	print_int(int n);
int	print_unsignedint(unsigned int d);
int	print_hex(unsigned int d, char c);
int	print_ptr(void *p);

#endif
