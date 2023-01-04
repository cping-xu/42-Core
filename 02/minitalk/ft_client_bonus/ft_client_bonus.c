/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:03:44 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/29 17:15:30 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	ft_error(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (1);
	i = 0;
	while (argv[1][i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_send_char(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(WAIT_TIME);
	}
}

void	ft_send_strlen(int len, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		i++;
		usleep(WAIT_TIME);
	}
}

void	received(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_putstr_fd("\n==========\n", 1);
		ft_putstr_fd("Received!", 1);
		ft_putstr_fd("\n==========\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		len;
	int		i;

	pid = ft_atoi(argv[1]);
	if (ft_error(argc, argv) || pid <= 0)
	{
		write(1, "Invalid input.\n", 15);
		return (0);
	}
	len = ft_strlen(argv[2]);
	i = 0;
	ft_send_strlen(len, pid);
	while (argv[2][i])
	{
		ft_send_char(argv[2][i], pid);
		i++;
	}
	signal(SIGUSR2, received);
	ft_send_char(argv[2][i], pid);
}
