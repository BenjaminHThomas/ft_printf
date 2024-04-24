/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:43:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/24 09:57:37 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create_pstr(char **pstr, long unsigned int address)
{
	int	i;

	i = 2;
	(*pstr)[0] = '0';
	(*pstr)[1] = 'x';
	while (address >= 16)
	{
		(*pstr)[i] = HEX_BASE[address % 16];
		address /= 16;
		i++;
	}
	(*pstr)[i] = HEX_BASE[address % 16];
}

static char	*p_string(long unsigned int address)
{
	char	*pstr;

	if (!address)
	{
		pstr = malloc(6);
		if (!pstr)
			return (NULL);
		ft_strlcpy(pstr, "(nil)", 6);
		return (pstr);
	}
	pstr = malloc(sizeof(void *) * 2 + 3);
	if (!pstr)
		return (NULL);
	ft_bzero(pstr, sizeof(void *) * 2 + 3);
	create_pstr(&pstr, address);
	return (pstr);
}

static int	print_p_left(t_flags *flags, char *pstr)
{
	int	len;

	len = printf_putstr(pstr, flags->prec_val, ft_memcmp(pstr, "(nil)", 5));
	if (flags->width_val > len)
	{
		pad_output(32, flags->width_val - len);
		len = flags->width_val;
	}
	free(pstr);
	return (len);
}

static int	print_p_right(t_flags *flags, char *pstr)
{
	int	len;

	if (flags->width_val > init_len(pstr, flags))
	{
		pad_output(32, flags->width_val - init_len(pstr, flags));
		printf_putstr(pstr, flags->prec_val, ft_memcmp(pstr, "(nil)", 5));
		free(pstr);
		return (flags->width_val);
	}
	len = printf_putstr(pstr, flags->prec_val, ft_memcmp(pstr, "(nil)", 5));
	free(pstr);
	return (len);
}

int	print_p(t_flags *flags, va_list ap)
{
	long unsigned int	address;
	char				*pstr;

	address = (long unsigned int)va_arg(ap, void *);
	pstr = p_string(address);
	if (flags->b_minus)
		return (print_p_left(flags, pstr));
	else
		return (print_p_right(flags, pstr));
}
