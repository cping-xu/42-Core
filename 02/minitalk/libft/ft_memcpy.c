/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:00:29 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/12 16:49:58 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	if (!(dst) && !(src))
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

/*#include <stdio.h>
#include <string.h>

int main (void)
{
	char	a[] = "abcdefghijkl";
	char	b[] = "abcdefghijkl";
	char	c[] = "12345678";
	char	d[] = "12345678";

	memcpy(a+2, c, 5);
    printf("%s\n", a);
	ft_memcpy(b+2, d, 5);
	printf("%s\n", b);
    return 0;
}*/
