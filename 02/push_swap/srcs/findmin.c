/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findmin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:37:15 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:24:12 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	findmin(char **a)
{
	int	i;
	int	j;
	int	k;
	int	min;

	k = 1;
	min = 0;
	while (a[k])
	{
		i = ft_atoi(a[min]);
		j = ft_atoi(a[k]);
		if (j < i)
			min = k;
		k++;
	}
	return (min);
}

void	pushmin(char **a)
{
	int	i;
	int	min;

	i = 0;
	min = findmin(a);
	while (a[i + 1])
		i++;
	if (min > i / 2)
	{
		while (min <= i)
		{
			rra(a);
			min++;
		}
	}
	else if (min == 1)
		sa(a);
	else if (min <= i / 2)
	{
		while (min >= 1)
		{
			ra(a);
			min--;
		}
	}
}
