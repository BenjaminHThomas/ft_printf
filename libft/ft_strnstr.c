/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:29:03 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/12 10:10:55 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>
#include <stddef.h>*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*plit;
	const char	*pbig;

	if (little[0] == 0)
		return ((char *)big);
	while (*big && len)
	{
		plit = little;
		while (*big != *little && len && *big++)
			len--;
		if (*big == *little && len)
		{
			pbig = big;
			while (*big == *plit && len && *big && *plit)
			{
				big++;
				plit++;
				len--;
			}
		}
		if (!*plit)
			return ((char *)pbig);
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*big = "oh no not the empty string!";
	char	*little = "";
	char	*big_mine;
	big_mine = ft_strnstr(big, little, 20);
	printf("Mine: %s", big_mine);
	return (0);
}
*/
