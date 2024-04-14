/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:13:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/14 16:51:28 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*plst;
	t_list	*newlst;
	t_list	*node;
	void	*fret;

	if (!lst || !f || !del)
		return (NULL);
	plst = lst;
	newlst = NULL;
	while (plst)
	{
		fret = f(plst->content);
		node = ft_lstnew(fret);
		if (!node)
		{
			del(fret);
			ft_lstclear(&newlst, (*del));
			return (newlst);
		}
		ft_lstadd_back(&newlst, node);
		plst = plst->next;
	}
	return (newlst);
}
