/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:27:42 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/25 13:04:40 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_digits(unsigned int n)
{
	int	num;

	if (n == 0)
		return (1);
	num = 0;
	while (n > 0)
	{
		num++;
		n /= 10;
	}
	return (num);
}

static char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				num_len;

	num_len = num_digits(n);
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

	flags->b_uns = 1;
	i = va_arg(ap, unsigned int);
	numstr = ft_uitoa(i);
	if (flags->b_minus)
		len = print_d_left(flags, numstr);
	else
		len = print_d_right(flags, numstr);
	free(numstr);
	return (len);
}
