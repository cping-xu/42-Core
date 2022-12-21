/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:11:35 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:25:42 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	findmax(char **b)
{
	int	i;
	int	j;
	int	k;
	int	min;

	k = 1;
	min = 0;
	while (b[k])
	{
		i = ft_atoi(b[min]);
		j = ft_atoi(b[k]);
		if (j > i)
			min = k;
		k++;
	}
	return (min);
}

int	findmax2(char **b, int max)
{
	int	i;
	int	j;
	int	k;
	int	min;

	k = 1;
	min = 0;
	while (b[k])
	{
		i = ft_atoi(b[min]);
		j = ft_atoi(b[k]);
		if (j > i && k != max)
			min = k;
		k++;
	}
	return (min);
}

void	swapmax(char **a, char **b, int i, int max)
{
	int	max2;

	max2 = findmax2(b, max);
	if (max2 == 0 && ft_atoi(a[0]) > ft_atoi(b[max]))
		return ;
	else if (max2 == 1 && ft_atoi(a[0]) > ft_atoi(b[max]))
		sb(b);
	else if (max == 1)
		sb(b);
	else if (max > i / 2)
	{
		while (max <= i)
		{
			rrb(b);
			max++;
		}
	}
	else if (max <= i / 2)
	{
		while (max >= 1)
		{
			rb(b);
			max--;
		}
	}
}

void	pushmax(char **a, char **b)
{
	int	i;
	int	max;

	i = 0;
	max = findmax(b);
	while (b[i + 1])
		i++;
	swapmax(a, b, i, max);
}
