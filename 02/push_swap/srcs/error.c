/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:30:48 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/06 22:21:01 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checksame(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_intcmp(str[i], str[j]) == 0)
				return (-1);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	errorhandle(char **str)
{
	if (checknum(str) == -1)
		return (1);
	if (checksame(str) == -1)
		return (1);
	if (checkint(str) == -1)
		return (1);
	if (checkplace(str) == -1)
		return (2);
	if (checkac(str) < 2)
		return (1);
	else
		return (0);
}
