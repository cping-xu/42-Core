/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:04:47 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/12 16:25:14 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	slen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	checksame(char const *set, char const b)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == b)
			return (1);
		i++;
	}
	return (0);
}

static int	len(char const *s1, char const *set)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (checksame(set, s1[i]))
		i++;
	if (i < slen(s1))
	{
		while (s1[i] != '\0')
		{
			l++;
			i++;
		}
		i = i - 1;
		while (checksame(set, s1[i]))
		{
			i--;
			l--;
		}
	}
	return (l);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	if (!(s1) || !(set))
		return (NULL);
	l = len(s1, set);
	temp = malloc((l + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	while (checksame(set, s1[i]))
		i++;
	while (j < l)
	{
		temp[j] = s1[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

/*#include <stdio.h>
int main()
{
	printf("%s\n", ft_strtrim("     x     x", " x"));
}*/
