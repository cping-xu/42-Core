/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:10:52 by cping-xu          #+#    #+#             */
/*   Updated: 2023/01/04 17:41:41 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>

typedef struct s_image
{
	void	*wall;
	void	*c;
	void	*p;
	void	*enemy1;
	void	*enemy2;
	void	*white;
	void	*mexit1;
	void	*mexit2;
}	t_image;

typedef struct s_display
{
	int		x;
	int		y;
	int		fps;
	void	*enemy;
	void	*mexit;
}	t_display;

typedef struct s_player
{
	int		i;
	int		j;
}	t_player;

typedef struct s_check
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;
}	t_check;

typedef struct s_data
{
	int			i;
	int			j;
	int			l;
	int			h;
	int			t;
	int			len;
	int			height;
	int			step;
	char		**map;
	void		*mlx;
	void		*win;
	t_image		b;
	t_display	c;
	t_player	d;
	t_check		e;
}	t_data;

char	**getmap(char *maps);
void	putimage(char **map, t_data *a);
void	image(t_data *a);
int		collect(t_data *a);
int		moveup(t_data *a);
int		movedown(t_data *a);
int		moveleft(t_data *a);
int		moveright(t_data *a);
int		ft_error(t_data *a, char **av);
int		valid(t_data *a);
int		checkav(char **av);

#endif