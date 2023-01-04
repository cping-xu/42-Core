/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:03:58 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/07 16:45:02 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	t;

	i = 0;
	p = (unsigned char *)s;
	t = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == t)
		{
			return ((void *)&p[i]);
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "herzeo woreld";
	int to = 'o';

	printf("%s\n", ft_memchr(str, to, 6));
	printf("%s\n", memchr(str, to, 6));
}*/
