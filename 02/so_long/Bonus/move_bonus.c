/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:46:17 by cping-xu          #+#    #+#             */
/*   Updated: 2023/01/02 19:10:28 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	pos(t_data *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map[i])
	{
		j = 0;
		while (a->map[i][j])
		{
			if (a->map[i][j] == 'P')
			{
				a->d.j = j;
				a->d.i = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	moveup(t_data *a)
{
	pos(a);
	if (a->map[a->d.i - 1][a->d.j] == '1')
		return (0);
	if (a->map[a->d.i - 1][a->d.j] == 'E' && collect(a) > 0)
		return (0);
	if (a->map[a->d.i - 1][a->d.j] == '2')
	{
		ft_putstr_fd("YOU DIED !\n", 2);
		exit (-1);
	}
	if (a->map[a->d.i - 1][a->d.j] == 'E' && collect(a) == 0)
	{
		ft_putstr_fd("YOU WIN !\n", 1);
		exit (0);
	}
	a->map[a->d.i][a->d.j] = '0';
	a->map[a->d.i - 1][a->d.j] = 'P';
	if (collect(a) == 0)
		a->c.mexit = a->b.mexit2;
	a->step++;
	mlx_clear_window(a->mlx, a->win);
	putimage(a->map, a);
	return (0);
}

int	movedown(t_data *a)
{
	pos(a);
	if (a->map[a->d.i + 1][a->d.j] == '1')
		return (0);
	if (a->map[a->d.i + 1][a->d.j] == 'E' && collect(a) > 0)
		return (0);
	if (a->map[a->d.i + 1][a->d.j] == '2')
	{
		ft_putstr_fd("YOU DIED !\n", 2);
		exit (-1);
	}
	if (a->map[a->d.i + 1][a->d.j] == 'E' && collect(a) == 0)
	{
		ft_putstr_fd("YOU WIN !\n", 1);
		exit (0);
	}
	a->map[a->d.i][a->d.j] = '0';
	a->map[a->d.i + 1][a->d.j] = 'P';
	if (collect(a) == 0)
		a->c.mexit = a->b.mexit2;
	a->step++;
	mlx_clear_window(a->mlx, a->win);
	putimage(a->map, a);
	return (0);
}

int	moveleft(t_data *a)
{
	pos(a);
	if (a->map[a->d.i][a->d.j - 1] == '1')
		return (0);
	if (a->map[a->d.i][a->d.j - 1] == 'E' && collect(a) > 0)
		return (0);
	if (a->map[a->d.i][a->d.j - 1] == '2')
	{
		ft_putstr_fd("YOU DIED !\n", 2);
		exit (-1);
	}
	if (a->map[a->d.i][a->d.j - 1] == 'E' && collect(a) == 0)
	{
		ft_putstr_fd("YOU WIN !\n", 1);
		exit (0);
	}
	a->map[a->d.i][a->d.j] = '0';
	a->map[a->d.i][a->d.j - 1] = 'P';
	if (collect(a) == 0)
		a->c.mexit = a->b.mexit2;
	a->step++;
	mlx_clear_window(a->mlx, a->win);
	putimage(a->map, a);
	return (0);
}

int	moveright(t_data *a)
{
	pos(a);
	if (a->map[a->d.i][a->d.j + 1] == '1')
		return (0);
	if (a->map[a->d.i][a->d.j + 1] == 'E' && collect(a) > 0)
		return (0);
	if (a->map[a->d.i][a->d.j + 1] == '2')
	{
		ft_putstr_fd("YOU DIED !\n", 2);
		exit (-1);
	}
	if (a->map[a->d.i][a->d.j + 1] == 'E' && collect(a) == 0)
	{
		ft_putstr_fd("YOU WIN !\n", 1);
		exit (0);
	}
	a->map[a->d.i][a->d.j] = '0';
	a->map[a->d.i][a->d.j + 1] = 'P';
	if (collect(a) == 0)
		a->c.mexit = a->b.mexit2;
	a->step++;
	mlx_clear_window(a->mlx, a->win);
	putimage(a->map, a);
	return (0);
}
