/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:09:01 by cping-xu          #+#    #+#             */
/*   Updated: 2023/02/18 12:14:22 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_mutex);
	if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
	{
		print_status(philo, "d");
		check_done(philo, 1);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return (1);
	}
	else if (philo->info->num_must_eat > 0 && philo->eat >= \
			philo->info->num_must_eat)
	{
		philo->info->num_full_philo++;
		if (philo->info->num_full_philo >= philo->info->num_philo)
		{
			check_done(philo, 1);
			print_status(philo, "f");
			pthread_mutex_unlock(&philo->info->eat_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->info->eat_mutex);
	return (0);
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	ft_sleep(philo, philo->info->time_to_eat);
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->eat += 1;
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->info->eat_mutex);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
}

int	check_done(t_philo *philo, int temp)
{
	pthread_mutex_lock(&philo->info->finish_mutex);
	if (temp)
	{
		philo->info->finish = 1;
		pthread_mutex_unlock(&philo->info->finish_mutex);
		return (1);
	}
	if (philo->info->finish)
	{
		pthread_mutex_unlock(&philo->info->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->finish_mutex);
	return (0);
}

void	*philo_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (1)
	{
		if (check_done(philo, 0))
			return (0);
		eat(philo);
		print_status(philo, "is sleeping");
		ft_sleep(philo, philo->info->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (init_info(&info, ac, av))
		return (0);
	if (init_philo(&info))
		return (free_info(&info));
	if (init_mutex(&info))
		return (free_destroy(&info));
	if (create_philo(&info))
		return (0);
	destroy(&info);
}
