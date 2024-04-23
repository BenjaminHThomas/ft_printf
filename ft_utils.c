/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:47:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/23 14:38:40 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

#include <stdio.h>
void	print_flags(t_flags *flags)
{
	printf("minus: %d\n", flags->b_minus);
	printf("plus: %d\n", flags->b_plus);
	printf("space: %d\n", flags->b_space);
	printf("hash: %d\n", flags->b_hash);
	printf("zero: %d\n", flags->b_zero);
	printf("width: %d\n", flags->width_val);
	printf("precision: %d\n", flags->prec_val);
	printf("specifier: %c\n", flags->specifier);
}
