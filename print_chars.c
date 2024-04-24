/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:52:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/24 10:28:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s_left(t_flags *flags, char *str, int null_cmp)
{
	int	len;

	len = printf_putstr(str, flags->prec_val, null_cmp);
	if (flags->width_val > len)
	{
		pad_output(32, flags->width_val - len);
		len = flags->width_val;
	}
	return (len);
}

int	print_s_right(t_flags *flags, char *str, int null_cmp)
{
	int	len;

	len = init_len(str, flags);
	if (flags->width_val > len)
	{
		pad_output(32, flags->width_val - len);
		printf_putstr(str, flags->prec_val, null_cmp);
		return (flags->width_val);
	}
	return (printf_putstr(str, flags->prec_val, null_cmp));
}

int	print_s(t_flags *flags, va_list ap)
{
	char	*str;
	int		null_cmp;

	str = va_arg(ap, char *);
	if (!str)
		null_cmp = 0;
	if (!str && (flags->prec_val >= 6 || flags->prec_val == -1))
		str = "(null)";
	else if (!str)
		str = "";
	else
		null_cmp = 1;
	if (flags->b_minus)
		return (print_s_left(flags, str, null_cmp));
	else
		return (print_s_right(flags, str, null_cmp));
}

int	print_c(t_flags *flags, va_list ap)
{
	unsigned char	c;
	int				width;
	int				len;

	len = 1;
	width = flags->width_val;
	c = va_arg(ap, int);
	if (flags->b_minus)
	{
		ft_putchar_fd(c, 1);
		if (width > 1)
		{
			pad_output(32, width - 1);
			len = width;
		}
		return (len);
	}
	if (width > 1)
	{
		pad_output(32, width - 1);
		len = width;
	}
	ft_putchar_fd(c, 1);
	return (len);
}
