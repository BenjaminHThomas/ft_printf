/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:43:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/26 12:02:49 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create_pstr(char **pstr, long unsigned n, t_flags *flags)
{
	int	i;
	int	pad_size;

	i = num_digits(n, 16);
	pad_size = max(flags->prec_val - i, 0) + 1;
	i += pad_size;
	(*pstr)[0] = '0';
	(*pstr)[1] = 'x';
	while (pad_size >= 2)
		(*pstr)[pad_size--] = '0';
	while (n >= 16)
	{
		(*pstr)[i] = HEX_BASE[n % 16];
		n /= 16;
		i--;
	}
	(*pstr)[i] = HEX_BASE[n % 16];
}

static char	*p_string(long unsigned n, t_flags *flags)
{
	char	*pstr;
	int		size;

	if (!n)
	{
		pstr = malloc(6);
		if (!pstr)
			return (NULL);
		ft_strlcpy(pstr, "(nil)", 6);
		return (pstr);
	}
	size = max((sizeof(void *) * 2), flags->prec_val);
	pstr = (char *)malloc(size + 2);
	if (!pstr)
		return (NULL);
	ft_bzero(pstr, size + 2);
	create_pstr(&pstr, n, flags);
	return (pstr);
}

int	print_p_left(t_flags *flags, char *pstr)
{
	int	len;

	len = printf_putstr(pstr, -1, ft_memcmp(pstr, "(nil)", 5));
	if (flags->width_val > len) 
	{
		pad_output(32, flags->width_val - len);
		len = flags->width_val;
	}
	free(pstr);
	return (len);
}

int	print_p_right(t_flags *flags, char *pstr)
{
	int	len;

	if (flags->width_val > ft_strlen(pstr))
	{
		pad_output(32, flags->width_val - ft_strlen(pstr));
		printf_putstr(pstr, -1, ft_memcmp(pstr, "(nil)", 5));
		free(pstr);
		return (flags->width_val);
	}
	len = printf_putstr(pstr, -1, ft_memcmp(pstr, "(nil)", 5));
	free(pstr);
	return (len);
}

int	print_p(t_flags *flags, va_list ap)
{
	long unsigned int	address;
	char				*pstr;

	address = (long unsigned int)va_arg(ap, void *);
	pstr = p_string(address, flags);
	if (flags->b_minus)
		return (print_p_left(flags, pstr));
	else
		return (print_p_right(flags, pstr));
}
