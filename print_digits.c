/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:08:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/24 20:44:36 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	out_d_prefix(t_flags *flags, char *numstr, int *bool_prefix)
{
	if (flags->b_plus && *numstr != '-')
		ft_putchar_fd('+', 1);
	else if (flags->b_space && *numstr != '-')
		ft_putchar_fd(32, 1);
	else
		return ;
	*bool_prefix = 1;
}

static int	print_d_left(t_flags *flags, char *numstr)
{
	int	len;
	int	b_prefix;
	int	width;
	int	prec;

	b_prefix = 0;
	width = flags->width_val;
	prec = flags->prec_val;
	len = ft_strlen(numstr);
	out_d_prefix(flags, numstr, &b_prefix);
	if (flags->prec_val > len)
		pad_output('0', prec - len);
	printf_putstr(numstr, -1, 1);
	if (width > max(len, prec))
	{
		pad_output(get_padder(flags), width - max(len, prec) - b_prefix);
		return (width);
	}
	return (max(prec, len) + b_prefix);
}

static int	print_d_right(t_flags *flags, char *numstr)
{
	int	len;
	int	b_prefix;
	int	width;
	int	prec;

	len = ft_strlen(numstr);
	width = flags->width_val;
	prec = flags->prec_val;
	b_prefix = ((flags->b_plus || flags->b_space) && *numstr != '-');
	if (width > max(prec, len))
		pad_output(get_padder(flags), width - max(prec, len) - b_prefix);
	out_d_prefix(flags, numstr, &b_prefix);
	if (prec > len)
		pad_output('0', prec - len);
	printf_putstr(numstr, -1, 1);
	if (width > prec)
		return (max(width, len));
	return (max(prec, len) + b_prefix);
}

int	print_digit(t_flags *flags, va_list ap)
{
	char	*numstr;
	int		i;
	int		len;

	len = 0;
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
