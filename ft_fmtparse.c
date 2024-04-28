/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 09:40:24 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/28 17:59:46 by bthomas          ###   ########.fr       */
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
	flags->prec_val = -1;
	flags->specifier = 0;
}

static void	parse_prec(char **fmt, t_flags *flags, va_list ap)
{
	(*fmt)++;
	if (**fmt == '*')
	{
		flags->prec_val = va_arg(ap, int);
		(*fmt)++;
		return ;
	}
	if (ft_isdigit(**fmt))
		flags->prec_val = printf_atoi(fmt);
	else
		flags->prec_val = 0;
}

static void	parse_width(char **fmt, t_flags *flags, va_list ap)
{
	if (**fmt == '*')
	{
		flags->width_val = va_arg(ap, int);
		(*fmt)++;
	}
	else
		flags->width_val = printf_atoi(fmt);
}

static void	process_flags(char **fmt, t_flags *flags, va_list ap)
{
	reset_flags(flags);
	while (in(FLAG_CHARS, **fmt))
	{
		if (**fmt == '-')
			flags->b_minus = 1;
		if (**fmt == '+')
			flags->b_plus = 1;
		if (**fmt == '0')
			flags->b_zero = 1;
		if (**fmt == 32)
			flags->b_space = 1;
		if (**fmt == '#')
			flags->b_hash = 1;
		(*fmt)++;
	}
	if (ft_isdigit(**fmt) || **fmt == '*')
		parse_width(fmt, flags, ap);
	if (**fmt == '.')
		parse_prec(fmt, flags, ap);
}

int	ft_fmtparse(char *fmt, va_list ap)
{
	int		len;
	int		print_return;
	t_flags	flags;

	len = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt++))
		{
			process_flags(&fmt, &flags, ap);
			print_return = ft_printvarg(&fmt, &flags, ap);
			if (print_return != -1)
				len += (print_return);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			len++;
		}
		fmt++;
	}
	if (print_return == -1)
		return (-1);
	return (len);
}
