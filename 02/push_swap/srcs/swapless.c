/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapless.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:35:46 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:33:51 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swaptwo(char **a)
{
	if (ft_intcmp(a[0], a[1]) > 0)
		sa(a);
}

void	swapthree(char **a)
{
	int	i;
	int	j;
	int	k;

	i = ft_atoi(a[0]);
	j = ft_atoi(a[1]);
	k = ft_atoi(a[2]);
	if (k > i && k > j && j < i)
		sa(a);
	else if (i > j && i > k && j > k)
	{
		sa(a);
		rra(a);
	}
	else if (i > j && i > k && k > j)
		ra(a);
	else if (i < j && i < k && j > k)
	{
		sa (a);
		ra (a);
	}
	else if (k < i && k < j && j > i)
		rra(a);
}

int	swapless(char **a, char **b, int num)
{
	if (num == 2)
		swaptwo(a);
	else if (num == 3)
		swapthree(a);
	else if (num <= 5)
		swapmore(a, b, num);
	return (0);
}
