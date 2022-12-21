/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:34:23 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/06 22:43:58 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_intcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = ft_atoi(s1);
	j = ft_atoi(s2);
	if (i < j)
		return (-1);
	else if (j < i)
		return (1);
	return (0);
}
