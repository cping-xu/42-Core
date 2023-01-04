/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:23:25 by cping-xu          #+#    #+#             */
/*   Updated: 2023/01/02 19:10:31 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	image(t_data *a)
{
	int		x;
	int		y;

	a->b.wall = mlx_xpm_file_to_image(a->mlx, "image/wall.xpm", &x, &y);
	a->b.c = mlx_xpm_file_to_image(a->mlx, "image/collect.xpm", &x, &y);
	a->b.p = mlx_xpm_file_to_image(a->mlx, "image/player.xpm", &x, &y);
	a->b.mexit1 = mlx_xpm_file_to_image(a->mlx, "image/mexit1.xpm", &x, &y);
	a->b.mexit2 = mlx_xpm_file_to_image(a->mlx, "image/mexit2.xpm", &x, &y);
	a->b.enemy1 = mlx_xpm_file_to_image(a->mlx, "image/enemy1.xpm", &x, &y);
	a->b.enemy2 = mlx_xpm_file_to_image(a->mlx, "image/enemy2.xpm", &x, &y);
	a->c.enemy = a->b.enemy1;
	a->c.mexit = a->b.mexit1;
}

void	putnum(t_data *a)
{
	char	*num;
	char	*final;

	num = ft_itoa(a->step);
	final = ft_strjoin("STEPS : ", num);
	mlx_string_put(a->mlx, a->win, 10, 10, 0xFFFF, final);
	free(num);
	free(final);
}

void	putimage(char **map, t_data *a)
{
	a->i = 0;
	a->h = 0;
	while (map[a->i])
	{
		a->j = 0;
		a->l = 0;
		while (map[a->i][a->j])
		{
			if (map[a->i][a->j] == '1')
				mlx_put_image_to_window(a->mlx, a->win, a->b.wall, a->l, a->h);
			if (map[a->i][a->j] == '2')
				mlx_put_image_to_window(a->mlx, a->win, a->c.enemy, a->l, a->h);
			if (map[a->i][a->j] == 'C')
				mlx_put_image_to_window(a->mlx, a->win, a->b.c, a->l, a->h);
			if (map[a->i][a->j] == 'P')
				mlx_put_image_to_window(a->mlx, a->win, a->b.p, a->l, a->h);
			if (map[a->i][a->j] == 'E')
				mlx_put_image_to_window(a->mlx, a->win, a->c.mexit, a->l, a->h);
			a->l = a->l + 50;
			a->j++;
		}
		a->h = a->h + 40;
		a->i++;
	}
	putnum(a);
}
