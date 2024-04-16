/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 09:40:24 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/16 18:01:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reset_flags(t_flags *flags)
{
	flags->b_minus = 0;
	flags->b_plus = 0;
	flags->b_space = 0;
	flags->b_hash = 0;
	flags->b_zero = 0;
	flags->width_val = 0;
	flags->prec_val = 0;
	flags->specifier = 0;
}

static void	process_flags(char **fmt, t_flags *flags)
{
	reset_flags(flags);
	if (ft_isdigit(**fmt))
		flags->width_val = printf_atoi(fmt);
	while (in(FLAG_CHARS, **fmt))
	{
		if (**fmt == '.')
		{
			(*fmt)++;
			flags->prec_val = printf_atoi(fmt);
		}
		if (**fmt == '-')
			flags->b_minus = 1;
		if (**fmt == '+')
			flags->b_plus = 1;
		if (**fmt == 32)
			flags->b_space = 1;
		if (**fmt == '#')
			flags->b_hash = 1;
		if (**fmt == '0')
			flags->b_zero = 1;
		fmt++;
	}
}

int	ft_fmtparse(char *fmt, va_list ap)
{
	int		len;
	t_flags	flags;

	len = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt++))
		{
			process_flags(&fmt, &flags);
			len += ft_printvarg(&fmt/*, &flags*/, ap);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			len++;
		}
		fmt++;
	}
	return (len);
}
