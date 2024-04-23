/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:52:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/23 19:57:55 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_output(char c, int n)
{
	while (n)
	{
		ft_putchar_fd(c, 1);
		n--;
	}
}

static int	ft_putstr(char *s, int limit)
{
	int	len;

	len = 0;
	if (limit == -1)
		limit = ft_strlen(s);
	while (*s && limit)
	{
		ft_putchar_fd(*s, 1);
		len++;
		s++;
		limit--;
	}
	return (len);
}

static int	init_len(char *s, t_flags *flags)
{
	int	len;
	int	prec;

	prec = flags->prec_val;
	len = ft_strlen(s);
	if (prec == -1 || prec > len)
		return (len);
	return (prec);
}

int	print_s(t_flags *flags, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	len = init_len(str, flags);
	if (flags->b_minus)
	{
		len = ft_putstr(str, flags->prec_val);
		if (flags->width_val > len)
		{
			pad_output(32, flags->width_val - len);
			len = flags->width_val;
		}
		return (len);
	}
	if (flags->width_val > len)
	{
		pad_output(32, flags->width_val - len);
		ft_putstr(str, flags->prec_val);
		return (flags->width_val);
	}
	return (ft_putstr(str, flags->prec_val));
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
