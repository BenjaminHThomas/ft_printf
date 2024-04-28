/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:18:25 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/28 21:34:10 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_xlen(t_flags *flags, unsigned int n)
{
	int	numlen;
	int	maxflag;

	numlen = num_digits(n, 16);
	maxflag = max(flags->prec_val, flags->width_val);
	return (max(maxflag, numlen));
}

static void	create_xstr(char **xstr, unsigned int n, char *base, t_flags *flags)
{
	int	strlen;
	int	hash;

	hash = (2 * flags->b_hash) * (n != 0);
	strlen = max(flags->prec_val, num_digits(n, 16)) + hash - 1;
	if (hash)
	{
		(*xstr)[0] = '0';
		(*xstr)[1] = flags->specifier;
	}
	while (n != 0 && strlen >= hash)
	{
		(*xstr)[strlen] = base[n % 16];
		n /= 16;
		strlen--;
	}
	while (strlen >= hash)
	{
		(*xstr)[strlen] = '0';
		strlen--;
	}
}

static char	*x_string(unsigned int n, char *base, t_flags *flags)
{
	char	*xstr;
	int		numlen;

	numlen = get_xlen(flags, n);
	numlen += (2 * flags->b_hash);
	xstr = (char *)malloc(numlen * sizeof(char) + 1);
	if (!xstr)
		return (NULL);
	ft_bzero(xstr, numlen + 1);
	create_xstr(&xstr, n, base, flags);
	return (xstr);
}

int	print_x(t_flags *flags, va_list ap)
{
	unsigned int	x;
	char			*xstr;
	char			*base;

	if (flags->specifier == 'X')
		base = HEX_UP;
	else
		base = HEX_BASE;
	x = va_arg(ap, unsigned int);
	xstr = x_string(x, base, flags);
	if (flags->b_minus)
		return (print_p_left(flags, xstr));
	else
		return (print_p_right(flags, xstr));
}
