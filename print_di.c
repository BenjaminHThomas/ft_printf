/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:08:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/28 13:39:14 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	out_d_prefix(t_flags *flags, char **numstr)
{
	if (flags->b_plus && **numstr != '-' && flags->specifier != 'u')
		ft_putchar_fd('+', 1);
	else if (flags->b_space && **numstr != '-')
		ft_putchar_fd(32, 1);
	else if (**numstr == '-')
	{
		ft_putchar_fd('-', 1);
		(*numstr)++;
	}
	else
		return (0);
	return (1);
}

int	print_d_left(t_flags *flags, char *numstr)
{
	int	len;
	int	b_pref;
	int	width;
	int	prec;

	width = flags->width_val;
	prec = flags->prec_val;
	len = ft_strlen(numstr);
	b_pref = out_d_prefix(flags, &numstr);
	if (flags->prec_val > len)
		pad_output('0', prec - len + b_pref);
	printf_putstr(numstr, -1, 1);
	if (width > max(len, prec))
	{
		pad_output(get_padder(flags), width - max(len, prec));
		return (width);
	}
	return (max(prec, len) + b_pref);
}

int	print_d_right(t_flags *flags, char *numstr)
{
	int	len;
	int	b_pref;
	int	width;
	int	prec;

	len = ft_strlen(numstr);
	width = flags->width_val;
	prec = flags->prec_val;
	b_pref = ((((flags->b_plus && flags->specifier != 'u')
					|| flags->b_space) && *numstr != '-') || *numstr == '-');
	out_d_prefix(flags, &numstr);
	if (width > max(prec, len))
		pad_output(get_padder(flags), width - max(prec, len));
	if (prec > len)
		pad_output('0', prec - len);
	b_pref = printf_putstr(numstr, -1, 1);
	if (width > prec)
		return (max(width, len));
	return (max(prec, len) + b_pref);
}

int	print_digit(t_flags *flags, va_list ap)
{
	char	*numstr;
	int		i;
	int		len;

	i = va_arg(ap, int);
	numstr = ft_itoa(i);
	if (flags->b_minus)
	{
		len = print_d_left(flags, numstr);
		free(numstr);
		return (len);
	}
	len = print_d_right(flags, numstr);
	free(numstr);
	return (len);
}
