/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:37:19 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/12 16:11:50 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

static int	joinlen(char *s1, char *s2)
{
	int	l;

	l = len(s1) + len(s2);
	return (l);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (!(s1) || !(s2))
		return (NULL);
	dest = (char *)malloc((joinlen(s1, s2) + 1) * sizeof(char));
	if (!(dest))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	char	a[] = "abcde";
	char	b[] = "12345";
	printf("%s\n", ft_strjoin(a, b));
}*/
