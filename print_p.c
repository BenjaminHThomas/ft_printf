/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:43:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/24 07:41:32 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(va_list ap)
{
	long unsigned int	address;
	int					len;

	address = (long unsigned int)va_arg(ap, void *);
	if (!address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 2;
	write(1, "0x", 2);
	putnbr_base(address, HEX_BASE, &len);
	return (len);
}
/*
int	main(void)
{
	int	num = 10;
	void *ptr = &num;
	int ft = print_p(ptr);
	printf("\n");
	int	non = printf("%p", ptr);
	printf("\nmine: %d - real: %d", ft, non);
	return (0);
}
*/
