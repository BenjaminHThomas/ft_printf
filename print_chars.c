/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:52:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/19 12:02:46 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(/*t_flags *flags,*/ va_list ap)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(ap, char *);
	while (*str)
	{
		ft_putchar_fd(*str, 1);
		len++;
		str++;
	}
	return (len);
}

int	print_c(/*t_flags *flags,*/ va_list ap)
{
	unsigned char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}
