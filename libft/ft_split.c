/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:11:17 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/12 15:27:54 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdlib.h>
#include <string.h>*/

static char	*get_word(const char *s, int *start, char c)
{
	char	*word;
	int		i;
	int		end;

	end = *start;
	while (s[end] && s[end] != c)
		end++;
	i = 0;
	word = (char *)malloc((end - *start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (*start < end)
	{
		word[i] = s[*start];
		i++;
		(*start)++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**wlist;
	int		start;
	int		i;

	if (!s)
		return (NULL);
	wlist = (char **)malloc((ft_strlen(s) + 1) * sizeof(char *));
	if (!wlist)
		return (NULL);
	start = 0;
	i = 0;
	while (s[start])
	{
		while (s[start] == c && s[start])
			start++;
		if (!s[start])
			continue ;
		wlist[i] = get_word(s, &start, c);
		i++;
	}
	wlist[i] = 0;
	return (wlist);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "   lorem   ipsum dolor     sit amet,"
					"consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
	char	c = ' ';
	char	**wlist = ft_split(str, c);
	int		i;

	i = 0;
	while (wlist[i])
	{
		printf("%s\n", wlist[i]);
		i++;
	}
	return (0);
}
*/
