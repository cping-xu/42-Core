/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkav.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:51:55 by cping-xu          #+#    #+#             */
/*   Updated: 2023/01/04 18:59:01 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	checkav(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
		i++;
	i = i - 1;
	if (av[1][i--] == 'r')
	{
		if (av[1][i--] == 'e')
		{
			if (av[1][i] == 'b')
				return (0);
		}
	}
	return (1);
}

int	checkp(t_data *a)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (a->map[i])
	{
		j = 0;
		while (a->map[i][j])
		{
			if (a->map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (p == 1)
		return (0);
	return (1);
}
