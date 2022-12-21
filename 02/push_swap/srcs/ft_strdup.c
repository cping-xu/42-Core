/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:31:09 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:38:34 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_strdup(char **str, int k)
{
	int		i;
	int		j;
	int		l;
	char	*store;

	store = malloc(sizeof(char) * (k + 1));
	i = 1;
	j = 0;
	l = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			store[l] = str[i][j];
			j++;
			l++;
		}
		store[l] = ' ';
		l++;
		i++;
	}
	store[l] = '\0';
	return (store);
}
