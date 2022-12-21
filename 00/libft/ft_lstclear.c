/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:54:41 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/12 16:17:28 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if ((!del) || (!lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if (!del)
			return ;
		if (*lst)
		{
			(*del)((*lst)->content);
			free(*lst);
		}
		*lst = temp;
	}
}
