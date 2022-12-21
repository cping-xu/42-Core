/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:05:07 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:35:54 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checknum(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' && str[i][j + 1] >= '0' && str[i][j + 1] <= '9')
			j++;
		while (str[i][j] != '\0')
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (-1);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	checkac(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checkint(char **str)
{
	int			i;
	long long	num;

	i = 0;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > 2147483647 || num < -2147483648)
			return (-1);
		i++;
	}
	return (1);
}

int	checkplace(char **s1)
{
	int	i;
	int	j;
	int	a;
	int	k;

	k = 0;
	a = 0;
	while (s1[a + 1])
	{
		i = ft_atoi(s1[a]);
		j = ft_atoi(s1[a + 1]);
		if (i < j)
			k++;
		a++;
	}
	if (k == a)
		return (-1);
	return (1);
}
