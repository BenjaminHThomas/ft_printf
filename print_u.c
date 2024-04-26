/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:27:42 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/25 15:00:59 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				num_len;

	num_len = num_digits(n, 10);
	str = ft_calloc(num_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (num_len > 0)
	{
		str[num_len - 1] = n % 10 + '0';
		n /= 10;
		num_len--;
	}
	return (str);
}

int	print_u(t_flags *flags, va_list ap)
{
	int				len;
	char			*numstr;
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	numstr = ft_uitoa(i);
	if (flags->b_minus)
		len = print_d_left(flags, numstr);
	else
		len = print_d_right(flags, numstr);
	free(numstr);
	return (len);
}
