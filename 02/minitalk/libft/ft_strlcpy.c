/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:12:35 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/07 15:36:05 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[] = "asdfghjkl";
	char b[] = "qweew";
	char c[] = "asdfghjkl";
	char d[] = "qweew";
	printf("%zu\n", ft_strlcpy(b, a, 5));
	printf("a = %s\n", a);
	printf("%lu\n", strlcpy(d, c, 5));
	printf("c = %s\n", c);
}*/
