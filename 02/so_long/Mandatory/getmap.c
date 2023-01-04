/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:10:11 by cping-xu          #+#    #+#             */
/*   Updated: 2023/01/04 13:07:12 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>

char	*ft_join1(char *hold, char *buffer)
{
	char	*dest;

	dest = ft_strjoin1(hold, buffer);
	free(hold);
	return (dest);
}

char	**getmap(char *map)
{
	char	*line;
	char	*final;
	int		fd;

	line = "";
	final = ft_strdup("");
	fd = open(map, O_RDWR);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		final = ft_join1(final, line);
		free(line);
	}
	free(line);
	close(fd);
	return (ft_split(final, '\n'));
}
