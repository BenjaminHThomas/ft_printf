/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:43:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/07 13:43:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_pstr(char *pstr, long unsigned n, int len, t_flags *flags)
{
	int		numlen;
	int		pad_size;
	char	prefix;

	prefix = get_prefix(flags, &pstr);
	pstr[0] = prefix;
	numlen = num_digits(n, 16);
	pad_size = len - numlen - (prefix != 0);
	pstr[0 + (prefix != 0)] = '0';
	pstr[1 + (prefix != 0)] = 'x';
	numlen += pad_size + (prefix != 0) + 1;
	while (pad_size > 0)
	{
		pstr[1 + pad_size] = '0';
		pad_size--;
	}
	while (n >= 16)
	{
		pstr[numlen] = HEX_BASE[n % 16];
		n /= 16;
		numlen--;
	}
	pstr[numlen] = HEX_BASE[n % 16];
	return (pstr);
}

static char	*p_string(long unsigned n, t_flags *flags, int len)
{
	char	*pstr;

	if (!n)
	{
		flags->b_null = 1;
		pstr = malloc(6);
		if (!pstr)
			return (NULL);
		ft_strlcpy(pstr, "(nil)", 6);
		return (pstr);
	}
	pstr = (char *)malloc(len + 3);
	if (!pstr)
		return (NULL);
	ft_bzero(pstr, len + 3);
	pstr = create_pstr(pstr, n, len, flags);
	return (pstr);
}

int	print_p_left(t_flags *flags, char *pstr)
{
	int		len;

	len = printf_putstr(pstr, -1, ft_memcmp(pstr, "(nil)", 5));
	if (flags->width_val > len)
	{
		pad_output(get_padder(flags), flags->width_val - len);
		len = flags->width_val;
	}
	free(pstr);
	return (len);
}

int	print_p_right(t_flags *flags, char *pstr)
{
	int	len;

	len = 0;
	if (flags->width_val > ft_strlen(pstr))
	{
		pad_output(get_padder(flags), flags->width_val - ft_strlen(pstr));
		printf_putstr(pstr, -1, ft_memcmp(pstr, "(nil)", 5));
		free(pstr);
		return (flags->width_val);
	}
	len += printf_putstr(pstr, -1, ft_memcmp(pstr, "(nil)", 5));
	free(pstr);
	return (len);
}

int	print_p(t_flags *flags, va_list ap)
{
	long unsigned int	address;
	char				*pstr;
	int					len;
	int					numlen;

	address = (long unsigned int)va_arg(ap, void *);
	numlen = num_digits(address, 16) + (flags->b_space || flags->b_plus);
	len = max(flags->width_val * flags->b_zero, flags->prec_val);
	len = numlen + max(len - 2 - numlen, 0);
	pstr = p_string(address, flags, len);
	if (flags->b_minus)
		return (print_p_left(flags, pstr));
	else
		return (print_p_right(flags, pstr));
}
