/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:45:30 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/26 21:11:35 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fdchar(char a, int l)
{
	write(1, &a, 1);
	l++;
	return (l);
}

int	ft_putuphex(unsigned int n, int l)
{
	char	*h;

	h = "0123456789ABCDEF";
	if (n < 0)
		n = n + 4294967295;
	if (n >= 16)
	{
		l = ft_putuphex(n / 16 + 0, l);
		l = ft_putuphex(n % 16 + 0, l);
	}
	else
		l = fdchar(h[n], l);
	return (l);
}
