/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:19:20 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:24:35 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushsmall(char **a, char **b, int t, int k)
{
	if (k <= t / 2)
	{
		while (k > 0)
		{
			ra(a);
			k--;
		}
		pb(a, b);
	}
	else
	{
		while (k < t)
		{
			rra(a);
			k++;
		}
		pb (a, b);
	}
}

int	findsmall(char **a, char **b, int t, int *p)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (a[i])
	{
		j = ft_atoi(a[i]);
		k = i;
		if (j <= t / 2)
		{
			pushsmall(a, b, t, i);
			i = -1;
		}
		i++;
	}
	*p = *p / 2;
	return (t + *p);
}
