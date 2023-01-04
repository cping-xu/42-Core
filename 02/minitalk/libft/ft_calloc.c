/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:15:56 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/23 10:16:00 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	bzero(void *str, size_t n)
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

/*#include <stdio.h>
int main()
{
	int i = 0;
	char *b = ft_calloc(5, 10);
	while (i < 60)
	{
		printf("%d\n", *b++);
		i++;
	}
}*/
