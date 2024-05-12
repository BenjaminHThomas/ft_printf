/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:29:56 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/12 19:45:23 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Shared utility functions */
#include "ft_printf.h"

int	append(char *body, char *att, int limit)
{
	int	i;
	int	j;

	if (!body || !att)
		return (1);
	i = ft_strlen(body);
	j = 0;
	if (limit == -1)
		limit = BUFF_SIZE;
	while (att[j] && j < limit)
	{
		body[i + j] = att[j];
		j++;
	}
	return (0);
}

void	reset_flags(t_data *data)
{
	ft_memset(&data->flags, 0, sizeof(t_flags));
	data->flags.prec = -1;
}

int	max(int i1, int i2)
{
	if (i1 > i2)
		return (i1);
	else
		return (i2);
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

int	printf_atoi(t_data *data)
{
	char	*pfmt;
	int		i;
	int		num;

	pfmt = (char *)data->fmt;
	i = data->fmt_idx;
	while (i)
	{
		pfmt++;
		i--;
	}
	num = ft_atoi(pfmt);
	while (ft_isdigit(data->fmt[data->fmt_idx]))
		data->fmt_idx++;
	return (num);
}
