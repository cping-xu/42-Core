/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:20:00 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/14 09:31:30 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fdchar(char a, int fd)
{
	write(fd, &a, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10 + 0, fd);
		ft_putnbr_fd(n % 10 + 0, fd);
	}
	else
	{
		fdchar(n + '0', fd);
	}
}
