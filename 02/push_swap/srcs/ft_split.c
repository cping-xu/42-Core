/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:34:27 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:38:37 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	check_c(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	cstr(char *s, char c)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && check_c(s[i], c))
			i++;
		if (s[i] != '\0')
			num++;
		while (s[i] != '\0' && !check_c(s[i], c))
			i++;
	}
	return (num);
}

static int	len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && !check_c(s[i], c))
		i++;
	return (i);
}

char	*word(char *s, char c)
{
	int		wlen;
	int		i;
	char	*dest;

	i = 0;
	wlen = len(s, c);
	dest = (char *)malloc(sizeof(char) * (wlen + 1));
	if (!(dest))
		return (NULL);
	while (i < wlen)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (cstr(s, c) + 1));
	if (!(str))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && check_c(s[i], c))
			i++;
		if (s[i] != '\0')
		{
			str[j] = word(&s[i], c);
			j++;
		}
		while (s[i] != '\0' && !check_c(s[i], c))
			i++;
	}
	str[j] = 0;
	return (str);
}
