/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:47:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/24 19:55:40 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_padder(t_flags *flags)
{
	if (flags->b_zero && flags->prec_val == -1)
		return ('0');
	else
		return (32);
}

int	in(char const *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

void	putnbr_base(long n, char *strbase, int *len)
{
	long int	n2;
	char		c;
	int			base;

	base = ft_strlen(strbase);
	n2 = n;
	if (n < 0)
	{
		write(1, "-", 1);
		n2 *= -1;
	}
	if (n2 >= base)
		putnbr_base(n2 / base, strbase, len);
	c = strbase[n2 % base];
	(*len)++;
	write(1, &c, 1);
}

int	printf_atoi(char **str)
{
	int	num;

	num = ft_atoi(*str);
	while (ft_isdigit(**str))
		++(*str);
	return (num);
}

int	is_printable(char c)
{
	unsigned char	c2;

	c2 = c;
	if (c2 >= 32 && c2 <= 126)
		return (1);
	if (c2 >= 9 && c2 <= 13)
		return (1);
	return (0);
}
