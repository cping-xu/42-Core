/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:08 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/26 18:42:01 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fdchar(char a, int l)
{
	write(1, &a, 1);
	l++;
	return (l);
}

int	ft_unsignednbr(unsigned int n, int l)
{
	if (n >= 10)
	{
		l = ft_unsignednbr(n / 10 + 0, l);
		l = ft_unsignednbr(n % 10 + 0, l);
	}
	else
	{
		l = fdchar(n + '0', l);
	}
	return (l);
}

/* #include <stdio.h>
int main()
{
	// ft_nbr(-233);
	printf("%u\n", -233);
} */
