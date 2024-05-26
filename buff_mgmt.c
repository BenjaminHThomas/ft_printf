/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:44:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/15 22:02:39 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Functions for managing the buffer */
#include "ft_printf.h"

int	char_to_buf(t_data *data, char c)
{
	if (data->buf_idx >= BUFF_SIZE)
		return (1);
	data->buff[data->buf_idx] = c;
	data->buf_idx++;
	data->len_out++;
	return (0);
}

int	to_buf(t_data *data, char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i] && data->buf_idx < BUFF_SIZE)
	{
		data->buff[data->buf_idx] = s[i];
		data->buf_idx++;
		i++;
		data->len_out++;
	}
	return (0);
}

void	buf_fmt(t_data *data, int n)
{
	if (!data || !n)
		return ;
	while (n)
	{
		data->buff[data->buf_idx] = data->fmt[data->fmt_idx];
		data->buf_idx++;
		data->fmt_idx++;
		n--;
		data->len_out++;
	}
	data->fmt_idx--;
}

/* print backwards all chars between & including index and most recent % */
int	buf_fmt_back(t_data *data)
{
	int		i;

	if (!data)
		return (1);
	i = data->fmt_idx;
	while (data->fmt_idx >= 0 && data->fmt[data->fmt_idx] != '%')
		data->fmt_idx--;
	buf_fmt(data, i - data->fmt_idx);
	return (0);
}
