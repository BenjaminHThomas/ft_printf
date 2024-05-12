/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:53:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/11 19:00:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_data(t_data *data, const char *format)
{
	data->fmt = format;
	data->fmt_idx = 0;
	data->len_out = 0;
	data->buff = ft_calloc(BUFF_SIZE, 1);
	data->buf_idx = 0;
	data->varg_len = 0;
	reset_flags(data);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;
	int		ret;

	if (!format)
		return (-1);
	va_start(data.ap, format);
	init_data(&data, format);
	ret = parse_fmt(&data);
	va_end(data.ap);
	if (ret == 0)
	{
		write(1, data.buff, data.buf_idx);
		ret = data.len_out;
	}
	free(data.buff);
	return (ret);
}
