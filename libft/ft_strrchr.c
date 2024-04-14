/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:09:14 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/12 16:59:12 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*ps;
	unsigned char	c2;

	c2 = (unsigned char)c;
	ps = NULL;
	while (*s)
	{
		if (*s == c2)
			ps = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (ps);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *str = ft_strrchr("teste", '\0');
	char *str2 = strrchr("teste", '\0');
	printf("mine: %s\nreal: %s", str, str2);
	return (0);
}
*/
