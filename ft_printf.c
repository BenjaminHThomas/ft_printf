/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:22:30 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/28 18:08:29 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	*fmt;

	if (!format)
		return (0);
	len = 0;
	fmt = ft_strdup(format);
	if (!fmt)
		return (0);
	va_start(ap, format);
	if (valid_fmt(&fmt))
		len += ft_fmtparse(fmt, ap);
	else
		len = -1;
	va_end(ap);
	free(fmt);
	return (len);
}
