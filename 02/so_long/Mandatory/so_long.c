/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:29:17 by cping-xu          #+#    #+#             */
/*   Updated: 2023/01/04 18:52:13 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	collect(t_data *a)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (a->map[i])
	{
		j = 0;
		while (a->map[i][j])
		{
			if (a->map[i][j] == 'C')
			{
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}

int	myclose(int keycode, t_data *a)
{
	int	x;

	if (keycode == 13 || keycode == 126)
		moveup(a);
	else if (keycode == 0 || keycode == 123)
		moveleft(a);
	else if (keycode == 1 || keycode == 125)
		movedown(a);
	else if (keycode == 2 || keycode == 124)
		moveright(a);
	else if (keycode == 53)
	{
		x = 0;
		while (a->map[x])
		{
			free(a->map[x]);
			x++;
		}
		free(a->map);
		mlx_destroy_window(a->mlx, a->win);
		exit(0);
	}
	return (0);
}

int	destroyexit(t_data *a)
{
	int	x;

	x = 0;
	while (a->map[x])
	{
		free(a->map[x]);
		x++;
	}
	free(a->map);
	mlx_destroy_window(a->mlx, a->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	a;

	if (ac == 2)
	{
		a.map = getmap(av[1]);
		if (ft_error(&a, av) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		a.step = 0;
		a.c.fps = 0;
		a.mlx = mlx_init();
		a.win = mlx_new_window(a.mlx, 1920, 1080, "so_long");
		image(&a);
		putimage(a.map, &a);
		mlx_hook(a.win, 2, (1L << 0), myclose, &a);
		mlx_hook(a.win, 17, (1L << 0), destroyexit, &a);
		mlx_loop(a.mlx);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
