/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:51:12 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/12 16:50:30 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	if (!(dst) && !(src))
		return (NULL);
	s = (char *)src;
	d = (char *)dst;
	if (dst < src)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
		return (d);
	}
	while (len-- != 0)
	{
		d[len] = s[len];
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

	memmove(a+2, c, 5);
    printf("%s\n", a);
	ft_memmove(b+2, d, 5);
	printf("%s\n", b);
    return 0;
}*/

/*#include <stdio.h>
#include <string.h>

int main (void)
{
    char string [] = "stackoverflow";
    char *third, *fourth;
    third = string;
    fourth = string;

    puts(string);
	ft_memmove(third+3, third, 9);
    puts(third);
    memmove(fourth+3, fourth, 9);
    puts(fourth);
    return 0;
}*/
