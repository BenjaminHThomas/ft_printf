/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:08:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/19 12:10:26 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(va_list ap)
{
	char	*numstr;
	int		i;
	int		len;

	len = 0;
	i = va_arg(ap, int);
	numstr = ft_itoa(i);
	if (!numstr)
		return (0);
	while (*numstr)
	{
		ft_putchar_fd(*numstr, 1);
		len++;
		numstr++;
	}
	return (len);
}
