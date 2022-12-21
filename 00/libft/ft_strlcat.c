/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:55:44 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/12 17:17:38 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	len(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	if (!(dst) && !(dstsize))
		return (len(src));
	j = len(dst);
	l = len(dst);
	k = len(src);
	if (j < dstsize)
	{
		while (src[i] != '\0' && j < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
		return (l + k);
	}
	return (dstsize + k);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[] = "aaaaaaaaaa";
	char b[] = "bbb";
	char c[] = "aaaaaaaaaa";
	char d[] = "bbb";
	printf("%zu\n", ft_strlcat(b, a, 8));
	printf("a = %s\n", b);
	printf("%lu\n", strlcat(d, c, 8));
	printf("c = %s\n", d);
}*/
