/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:45:53 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/26 18:41:18 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fdchar(char a, int l)
{
	write(1, &a, 1);
	l++;
	return (l);
}

int	ft_putptr(unsigned long n, int l)
{
	char	*h;

	h = "0123456789abcdef";
	if (n >= 16)
	{
		l = ft_putptr(n / 16 + 0, l);
		l = ft_putptr(n % 16 + 0, l);
	}
	else
	{
		l = fdchar(h[n], l);
	}
	return (l);
}

/* #include <stdio.h>

int main()
{
	int	i;

	i = printf("%p\n", "sdfghjkl");
	printf("%d\n", i);
	// putfront();
	// ft_putptr(0x104501fa4);
} */
