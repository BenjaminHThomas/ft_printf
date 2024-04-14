/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:47:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/14 15:41:04 by bthomas          ###   ########.fr       */
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
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "wow 1 wow";
	char c = '1';

	printf("%d\n", in(str, c));
	putnbr_base(12345, 16);
	return (0);
}
*/
