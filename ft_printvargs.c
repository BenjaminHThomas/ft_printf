/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:34:05 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/16 16:41:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_s(/*t_flags *flags,*/ va_list ap)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(ap, char *);
	while (*str)
	{
		ft_putchar_fd(*str, 1);
		len++;
		str++;
	}
	return (len);
}

static int	print_c(/*t_flags *flags,*/ va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printvarg(char *fmt, /*t_flags *flags,*/ va_list ap)
{
	int	len;

	len = 0;
	if (*fmt == 'c')
		len += print_c(/*&flags,*/ ap);
	else if (*fmt == 's')
		len += print_s(/*&flags,*/ ap);
	/*
	else if (*fmt == 'p')
		len += print_p(&flags, ap);
	else if (*fmt == 'd')
		len += print_d(&flags, ap);
	else if (*fmt == 'i')
		len += print_i(&flags, ap);
	else if (*fmt == 'u')
		len += print_u(&flags, ap);
	else if (*fmt == 'x' or *fmt == 'X')
		len += print_x(*fmt, &flags, ap);
	*/
	fmt++;
	return (len);
}
