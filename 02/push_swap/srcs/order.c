/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:22:30 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:38:18 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_initial_order(char **a, char **b, int content)
{
	int	i;
	int	s;
	int	t;

	t = 0;
	i = 0;
	s = 1;
	while (ft_atoi(a[i]) != content)
	{
		if (ft_atoi(a[i]) > content)
		{
			t = ft_atoi(b[i]) + 1;
			free(b[i]);
			b[i] = ft_itoa(t);
		}
		else
			s++;
		i++;
	}
	b[i] = ft_itoa(s);
}

char	**ft_set_order(char *str)
{
	int		i;
	char	**b;
	char	**a;

	a = ft_split(str, ' ');
	i = 0;
	while (a[i])
		i++;
	b = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (a[i])
	{
		ft_initial_order(a, b, ft_atoi(a[i]));
		i++;
	}
	i = 0;
	free_used(a);
	return (b);
}
