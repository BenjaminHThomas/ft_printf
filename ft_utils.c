/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:47:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/16 18:02:06 by bthomas          ###   ########.fr       */
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

void	putnbr_base(int n, int base)
{
	long int	n2;
	char		c;

	n2 = n;
	if (n < 0)
	{
		write(1, "-", 1);
		n2 *= -1;
	}
	if (n2 > base)
		putnbr_base(n2 / base, base);
	c = n2 % base + '0';
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
