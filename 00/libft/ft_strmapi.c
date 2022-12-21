/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:54:45 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/12 16:21:03 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*temp;
	char	*t;

	if (!(s) || !(f))
		return (NULL);
	t = (char *)s;
	temp = (char *)malloc(len(t) * sizeof(char) + 1);
	if (!(temp))
		return (NULL);
	i = 0;
	while (t[i] != '\0')
	{
		temp[i] = f(i, t[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
