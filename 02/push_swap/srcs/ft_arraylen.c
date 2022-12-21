/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:30:55 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/06 22:21:13 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	aclen(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			j++;
		}
		i++;
	}
	return (i - 1);
}

int	arraylen(char **str)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 1;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			j++;
			k++;
		}
		k++;
		i++;
	}
	return (k);
}
