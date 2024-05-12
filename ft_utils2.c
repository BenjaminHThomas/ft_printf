/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:35:44 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/11 20:01:40 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_out(t_data *data, char *out, int n, int is_prec)
{
	char	padchar;
	char	*padstr;

	if (!data || !out || n <= 0)
		return ;
	if (is_prec && in("dipuxX", data->flags.specifier))
		padchar = '0';
	else
		padchar = get_padder(data);
	padstr = (char *)ft_calloc(n + 1, 1);
	if (!padstr)
		return ;
	while (n--)
		padstr[n] = padchar;
	append(out, padstr, -1);
	free(padstr);
}

int	get_padder(t_data *data)
{
	char	spec;

	spec = data->flags.specifier;
	if (in("dipuxX", spec))
	{
		if (data->flags.b_zero && !data->flags.b_minus)
			return ('0');
	}
	return (32);
}

int	get_prefix(t_data *data)
{
	char	spec;

	spec = data->flags.specifier;
	if (!in("upxX", spec) && *data->strnum == '-')
		return ('-');
	if (spec != 'u' && data->flags.b_plus)
		return ('+');
	if (spec != 'u' && data->flags.b_space)
		return (32);
	else
		return (0);
}

int	num_digits(unsigned long int n, int base)
{
	int	numlen;

	if (base <= 0)
		return (-1);
	if (n == 0)
		return (1);
	numlen = 0;
	while (n)
	{
		n /= base;
		numlen++;
	}
	return (numlen);
}
