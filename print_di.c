/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:08:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/07 13:11:35 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_prefix(t_flags *flags, char **numstr)
{
	if (**numstr == '-')
		return ('-');
	if (flags->b_plus && flags->specifier != 'u')
		return ('+');
	if (flags->b_space && flags->specifier != 'u')
		return (32);
	return (0);
}

static int	out_d_prefix(t_flags *flags, char **numstr)
{
	char	spec;

	spec = flags->specifier;
	if (**numstr == '-')
	{
		(*numstr)++;
		return (write(1, "-", 1));
	}
	else if (flags->b_plus && spec != 'u')
		return (write(1, "+", 1));
	else if (flags->b_space && spec != 'u')
		return (write(1, " ", 1));
	else
		return (0);
}

int	print_d_left(t_flags *flags, char *numstr)
{
	int	len;
	int	b_prefix;
	int	width;
	int	prec;

	width = flags->width_val;
	prec = flags->prec_val;
	len = ft_strlen(numstr);
	b_prefix = out_d_prefix(flags, &numstr);
	if (prec > len)
		pad_output('0', prec - len + b_prefix);
	printf_putstr(numstr, -1, 1);
	if (width > max(len, prec))
	{
		pad_output(get_padder(flags), width - max(len, prec));
		return (width + b_prefix);
	}
	return (max(prec, len) + b_prefix);
}

int	print_d_right(t_flags *flags, char *numstr)
{
	int	len;
	int	strlen;
	int	width;
	int	prec;
	int	extra_char;

	extra_char = in("+ ", get_prefix(flags, &numstr));
	len = ft_strlen(numstr);
	width = flags->width_val;
	prec = flags->prec_val;
	if (get_padder(flags) == '0')
		out_d_prefix(flags, &numstr);
	if (width > max(prec, len))
		pad_output(get_padder(flags), width - max(prec, len));
	if (get_padder(flags) != '0')
		out_d_prefix(flags, &numstr);
	if (prec > len)
		pad_output('0', prec - len);
	strlen = printf_putstr(numstr, -1, 1);
	if (width > prec)
		return (max(width, len) + extra_char);
	return (max(prec, len) + strlen + extra_char);
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
		return (len - 1 * (i < 0));
	}
	len = print_d_right(flags, numstr);
	free(numstr);
	return (len);
}
