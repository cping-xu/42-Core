/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:02:56 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/29 16:15:25 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_receive_len(int *curr_bit, char **final, int *len, int signal)
{
	static int	len_val = 0;

	if (signal == SIGUSR2)
		len_val = len_val + ft_recursive_power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*curr_bit = 0;
		*final = ft_calloc_exit(len_val + 1, sizeof(char));
		*len = 1;
		len_val = 0;
		return ;
	}
	(*curr_bit)++;
}

void	ft_restart(int *len, char **final, int *i, siginfo_t *info)
{
	kill (info->si_pid, SIGUSR2);
	*len = 0;
	if (final)
	{
		ft_putendl_fd(*final, 1);
		free(*final);
		*final = 0;
	}
	*i = 0;
}

void	ft_receive(int signal, siginfo_t *info, void *data)
{
	static int	char_val = 0;
	static int	curr_bit = 0;
	static int	len = 0;
	static int	i = 0;
	static char	*final = 0;

	(void)data;
	if (!len)
		ft_receive_len(&curr_bit, &final, &len, signal);
	else
	{
		if (signal == SIGUSR2)
			char_val = char_val + ft_recursive_power(2, curr_bit);
		if (curr_bit == 7)
		{
			final[i++] = char_val;
			curr_bit = 0;
			if (char_val == 0)
				(ft_restart(&len, &final, &i, info));
			char_val = 0;
			return ;
		}
		curr_bit++;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = (getpid());
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = ft_receive;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		usleep(WAIT_TIME);
}
