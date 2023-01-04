/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:50:43 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/11 12:18:39 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	t;

	p = (char *)s;
	t = (char)c;
	i = len(p) - 1;
	if (t == 0)
		return (&p[i + 1]);
	while (i >= 0)
	{
		while (p[i] == t)
		{
			return (&p[i]);
		}
		i--;
	}
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[] = "herzeo woreld";
	int to = 'h';

	printf("%s\n", ft_strrchr(str, to));
	printf("%s\n", strrchr(str, to));
}*/
