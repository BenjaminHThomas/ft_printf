/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:34:05 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/28 17:48:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printvarg(char **fmt, t_flags *flags, va_list ap)
{
	int	len;

	len = 0;
	flags->specifier = **fmt;
	if (**fmt == 'c')
		len += print_c(flags, ap);
	else if (**fmt == 's')
		len += print_s(flags, ap);
	else if (**fmt == 'p')
		len += print_p(flags, ap);
	else if (**fmt == 'd' || **fmt == 'i')
		len += print_digit(flags, ap);
	else if (**fmt == 'u')
		len += print_u(flags, ap);
	else if (**fmt == 'x' || **fmt == 'X')
		len += print_x(flags, ap);
	else if (**fmt == '%')
		len = write(1, "%", 1);
	else
		return (-1);
	return (len);
}
