/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:05:55 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/24 10:23:55 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putstr(char *s, int limit, int null_cmp)
{
	int	len;

	len = 0;
	if (limit == -1 || null_cmp == 0)
		limit = ft_strlen(s);
	while (*s && limit)
	{
		ft_putchar_fd(*s, 1);
		len++;
		s++;
		limit--;
	}
	return (len);
}

void	pad_output(char c, int n)
{
	while (n)
	{
		ft_putchar_fd(c, 1);
		n--;
	}
}

int	init_len(char *s, t_flags *flags)
{
	int	len;
	int	prec;

	prec = flags->prec_val;
	len = ft_strlen(s);
	if (prec == -1 || prec > len)
		return (len);
	return (prec);
}
