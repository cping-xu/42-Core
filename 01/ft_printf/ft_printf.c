/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:10:44 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/28 20:58:53 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	check(const char *s, va_list a, int i, int l)
{
	if (s[i + 1] == 'c' && s[i] == '%')
		l = ft_putchar(va_arg(a, int), l);
	else if (s[i + 1] == 's' && s[i] == '%')
		l = ft_putstr(va_arg(a, char *), l);
	else if (s[i + 1] == 'p' && s[i] == '%')
	{
		l = ft_putchar('0', l);
		l = ft_putchar('x', l);
		l = ft_putptr(va_arg(a, unsigned long), l);
	}
	else if ((s[i + 1] == 'd' || s[i + 1] == 'i') && s[i] == '%')
		l = ft_putnbr(va_arg(a, int), l);
	else if (s[i + 1] == 'u' && s[i] == '%')
		l = ft_unsignednbr(va_arg(a, unsigned int), l);
	else if (s[i + 1] == 'x' && s[i] == '%')
		l = ft_putptr(va_arg(a, unsigned long), l);
	else if (s[i + 1] == 'X' && s[i] == '%')
		l = ft_putuphex(va_arg(a, unsigned int), l);
	else if (s[i + 1] == '%' && s[i] == '%')
		l = ft_putchar('%', l);
	else if (s[i] != '%')
		l = ft_putchar(s[i], l);
	return (l);
}

int	ft_printf(const char *s, ...)
{
	va_list	a;
	int		i;
	int		l;

	l = 0;
	i = 0;
	va_start(a, s);
	while (s[i] != '\0')
	{
		l = check(s, a, i, l);
		if (s[i] == '%' && s[i + 1] != '\0')
			i++;
		i++;
	}
	va_end(a);
	return (l);
}

/* #include <stdio.h>

int main()
{
	// char	a;
	// int	i;
	int	j;

	// a = 97;
	// i = printf("%d\n %c\n", 122, a);
	// // printf("%d\n %c\n", 122, a);
	// printf("i = %d\n", i);
	j = ft_printf("this is a %x\n", -1);
	// ft_printf("%s\n", "asdfghjkl");
	// ft_printf("%d\n %c\n", 122, a);
	printf("j = %d\n", j);
} */