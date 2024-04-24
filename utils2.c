/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:05:55 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/24 08:50:27 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf,h"

int	ft_putstr(char *s, int limit)
{
	int	len;

	len = 0;
	if (limit == -1)
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

