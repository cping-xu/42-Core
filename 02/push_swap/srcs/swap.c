/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:32:53 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:26:35 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	countac(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

void	swapmore2(char **a, char **b)
{
	int	bit;
	int	j;
	int	size;

	bit = 0;
	size = countac(a);
	while (checkplace(a) == 1)
	{
		j = 0;
		while (j < size)
		{
			if (ft_atoi(a[0]) >> bit & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (countac(b) > 0)
			pa(a, b);
		bit++;
	}
}

void	swapin(char **a, char **b, int k, int temp)
{
	while (k > 3)
	{
		pushmin(a);
		if (checkplace(a) == -1)
			break ;
		pb(a, b);
		k--;
	}
	swapthree(a);
	k = countac(a);
	while (k < temp)
	{
		pushmax(a, b);
		pa(a, b);
		if (ft_atoi(a[0]) > ft_atoi(a[1]))
			sa(a);
		k++;
	}
}

void	swapmore(char **a, char **b, int num)
{
	int	temp;
	int	i;
	int	k;
	int	p;

	i = 0;
	temp = countac(a);
	p = num;
	while (countac(a) > 5)
		num = findsmall(a, b, num, &p);
	k = countac(a);
	swapin(a, b, k, temp);
}

void	swap(char **a, char **b, int num)
{
	if (num < 102)
		swapmore(a, b, num);
	else
		swapmore2(a, b);
}
