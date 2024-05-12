/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:04:41 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/12 19:47:10 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_d_prefix(t_data *data, char *out)
{
	if (!data || !out)
		return (0);
	if (*data->strnum == '-')
	{
		append(out, "-", -1);
		return (1);
	}
	else if (data->flags.b_plus)
	{
		append(out, "+", -1);
		return (1);
	}
	else if (data->flags.b_space)
	{
		append(out, " ", -1);
		return (1);
	}
	return (0);
}

static int	get_len_di(t_data *data)
{
	int		len;
	int		width;
	int		prec;
	char	*strnum;
	int		extra_char;

	strnum = data->strnum;
	len = data->numlen;
	width = data->flags.width;
	prec = data->flags.prec;
	if (*strnum == '-' || data->flags.b_space || data->flags.b_plus)
		extra_char = 1;
	else
		extra_char = 0;
	if (*strnum == '0' && prec == 0 && width == 0)
		return (0);
	if (width > prec)
		return (max(width, len) + extra_char);
	else
		return (max(prec, len) + extra_char);
}

static int	di_left(t_data *data)
{
	char	*out;
	int		res;
	int		width_pad;
	int		prec_pad;
	int		extra_char;

	out = (char *)ft_calloc(data->varg_len + 1, 1);
	if (!out)
		return (1);
	extra_char = out_d_prefix(data, out);
	width_pad = data->flags.width - max(data->numlen, data->flags.prec)
		- extra_char;
	prec_pad = data->flags.prec - data->numlen
		+ (*data->strnum == '-');
	pad_out(data, out, prec_pad, 1);
	append(out, data->strnum + (*data->strnum == '-'), data->flags.prec);
	pad_out(data, out, width_pad, 0);
	res = to_buf(data, out);
	free(out);
	return (res);
}

static int	di_right(t_data *data)
{
	char	*out;
	int		res;
	int		width_pad;
	int		prec_pad;
	int		extra_char;

	out = (char *)ft_calloc(data->varg_len + 1, 1);
	if (!out)
		return (1);
	extra_char = ((data->flags.b_space || data->flags.b_plus)
			&& !(*data->strnum == '-')) + (*data->strnum == '-');
	width_pad = data->flags.width - max(data->numlen, data->flags.prec)
		- extra_char;
	prec_pad = data->flags.prec - data->numlen
		+ (*data->strnum == '-');
	if (width_pad && data->flags.b_zero)
		out_d_prefix(data, out);
	pad_out(data, out, width_pad, 0);
	if (!(width_pad && data->flags.b_zero))
		out_d_prefix(data, out);
	pad_out(data, out, prec_pad, 1);
	append(out, data->strnum + (*data->strnum == '-'), data->flags.prec);
	res = to_buf(data, out);
	free(out);
	return (res);
}

int	ft_printdi(t_data *data)
{
	int		d;
	int		res;

	d = va_arg(data->ap, int);
	data->strnum = ft_itoa(d);
	data->numlen = ft_strlen(data->strnum);
	if (d == 0 && data->flags.prec == 0)
		data->numlen = 0;
	if (d !=0 && data->flags.prec < data->numlen)
		data->flags.prec = -1;
	data->varg_len = get_len_di(data);
	if (data->varg_len && data->flags.b_minus)
		res = di_left(data);
	else if (data->varg_len)
		res = di_right(data);
	free(data->strnum);
	data->varg_len = 0;
	data->numlen = 0;
	return (res);
}
