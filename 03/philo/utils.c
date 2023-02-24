/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:59:58 by cping-xu          #+#    #+#             */
/*   Updated: 2023/02/17 19:15:02 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			s;
	long long	n;

	i = 0;
	s = 1;
	n = 0;
	if (str[i] == '-')
		s *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	j = 1;
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (-1);
		j++;
	}
	while (str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * s);
}

long long	get_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

void	print_status(t_philo *philo, const char *str)
{
	long long	t;

	pthread_mutex_lock(&philo->info->print_mutex);
	if (str[0] == 'd')
	{
		t = get_time() - philo->info->start_time;
		printf("%lld %d %s\n", t, philo->id, "died");
		printf("Philosophers %d Dead\n", philo->id);
	}
	else if (!check_done(philo, 0))
	{
		t = get_time() - philo->info->start_time;
		printf("%lld %d %s\n", t, philo->id, str);
	}
	pthread_mutex_unlock(&philo->info->print_mutex);
	if (str[0] == 'f')
		printf("Philosophers Success\n");
}

void	ft_sleep(t_philo *philo, long long ms)
{
	long long	t;

	t = get_time();
	while (!check_done(philo, 0) && (get_time() - t) < ms)
		usleep(100);
}
