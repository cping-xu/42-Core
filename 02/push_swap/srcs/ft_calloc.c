/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:34:13 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:38:40 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)(str + i)) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;

	if (size != 0 && count >= SIZE_MAX / size)
		return (NULL);
	c = malloc(count * size);
	if (!(c))
		return (NULL);
	bzero(c, count * size);
	return (c);
}
