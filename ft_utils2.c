/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:05:55 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/29 12:52:25 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max(int n1, int n2)
{
	if (!n1 && !n2)
		return (0);
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	min(int n1, int n2)
{
	if (!n1 && !n2)
		return (0);
	if (n1 > n2)
		return (n2);
	return (n1);
}

int	printf_putstr(char *s, int limit, int not_null)
{
	int	len;

	len = 0;
	if (limit == -1 || !not_null)
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
