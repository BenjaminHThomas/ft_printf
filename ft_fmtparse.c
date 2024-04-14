/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 09:40:24 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/14 19:40:11 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(t_flags flags)
{
	ft_memset(flags, 0, sizeof(t_flags));
}
