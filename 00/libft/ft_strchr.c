/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:38:38 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/11 10:58:59 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	len(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*p;
	char	t;

	p = (char *)s;
	t = (char)c;
	j = len(p);
	i = 0;
	while (i <= j)
	{
		while (p[i] == t)
			return (&p[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "herzeo woreld";
	int to = 'e';

	printf("%s\n", ft_strchr(str, to));
	printf("%s\n", strchr(str, to));
}*/
