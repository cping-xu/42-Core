/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:47 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/26 20:33:51 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fdchar(char a, int l)
{
	write(1, &a, 1);
	l++;
	return (l);
}

int	ft_putnbr(int n, int l)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		l = l + 11;
		return (l);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		l = l + 1;
		n = -n;
	}
	if (n >= 10)
	{
		l = ft_putnbr(n / 10 + 0, l);
		l = ft_putnbr(n % 10 + 0, l);
	}
	else
		l = fdchar(n + '0', l);
	return (l);
}
