/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:55:39 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/12 12:22:14 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*empty;
	t_list	*new;

	if ((!f) || (!del) || (!lst))
		return (NULL);
	empty = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!(new))
		{
			while (empty)
			{
				new = empty->next;
				(*del)(empty->content);
				free(empty);
				empty = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&empty, new);
		lst = lst->next;
	}
	return (empty);
}
