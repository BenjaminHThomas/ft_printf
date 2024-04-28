/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:47:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/28 18:22:01 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	valid_fmt(char **fmt)
{
	int		i;

	i = 0;
	while ((*fmt)[i])
	{
		if ((*fmt)[i] == '%')
		{
			while (in(FLAG_CHARS, (*fmt)[i + 1]))
				i++;
			while (ft_isdigit((*fmt)[i + 1])
				|| (*fmt)[i + 1] == '*'
				|| (*fmt)[i + 1] == '.')
				i++;
			if ((*fmt)[i + 1] == '%')
				i++;
			else if (!in(SPECS, (*fmt)[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

char	get_padder(t_flags *flags)
{
	if (flags->b_zero)
		return ('0');
	else
		return (32);
}

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

int	printf_atoi(char **str)
{
	int	num;

	num = ft_atoi(*str);
	while (ft_isdigit(**str))
		++(*str);
	return (num);
}

int	num_digits(unsigned long int n, int base)
{
	int	num;

	if (n == 0)
		return (1);
	num = 0;
	while (n != 0)
	{
		num++;
		n /= base;
	}
	return (num);
}
