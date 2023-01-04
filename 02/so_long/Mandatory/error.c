/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:12:07 by cping-xu          #+#    #+#             */
/*   Updated: 2023/01/04 12:30:02 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	mapsize(t_data *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map[i])
	{
		j = 0;
		while (a->map[i][j])
			j++;
		i++;
	}
	if (i == j)
		return (1);
	a->len = j;
	a->height = i;
	return (0);
}

int	validity(t_data *a)
{
	a->e.c = 0;
	a->e.e = 0;
	a->e.p = 0;
	a->e.i = 0;
	while (a->map[a->e.i])
	{
		a->e.j = 0;
		while (a->map[a->e.i][a->e.j])
		{
			if (a->map[a->e.i][a->e.j] == 'C')
				a->e.c++;
			if (a->map[a->e.i][a->e.j] == 'P')
				a->e.p++;
			if (a->map[a->e.i][a->e.j] == 'E')
				a->e.e++;
			a->e.j++;
		}
		a->e.i++;
	}
	if (a->e.c < 1 || a->e.p != 1 || a->e.e < 1)
		return (1);
	return (0);
}

int	colwall(t_data *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a->map[i])
	{
		j = 0;
		if (a->map[i][j] != '1')
			return (1);
		while (a->map[i][j])
			j++;
		if (a->map[i][j - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	rowwall(t_data *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map[i])
	{
		j = 0;
		if (i == 0)
		{
			while (a->map[i][j])
			{
				if (a->map[i][j] != '1')
					return (1);
				j++;
			}
		}
		i++;
	}
	j = -1;
	while (a->map[i - 1][++j])
		if (a->map[i - 1][j] != '1')
			return (1);
	return (0);
}

int	ft_error(t_data *a)
{
	if (mapsize(a) == 1)
		return (1);
	if (validity(a) == 1)
		return (1);
	if (rowwall(a) == 1)
		return (1);
	if (colwall(a) == 1)
		return (1);
	if (valid(a) == 1)
		return (1);
	return (0);
}
