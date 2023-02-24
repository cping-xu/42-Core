/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:48:41 by cping-xu          #+#    #+#             */
/*   Updated: 2023/02/18 12:11:26 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info *info, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (print_error("Error: ac is not 5 or 6\n"));
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (info->num_philo < 1 || info->time_to_die < 1 || \
			info->time_to_eat < 1 || info->time_to_sleep < 1)
		return (print_error("Error: invalid input\n"));
	if (ac == 6)
	{
		info->num_must_eat = ft_atoi(av[5]);
		if (info->num_must_eat < 1)
			return (print_error("Error: wrong input\n"));
	}
	else
		info->num_must_eat = -1;
	info->finish = 0;
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (print_error("Error: forks mutex_init\n"));
		i++;
	}
	if (pthread_mutex_init(&info->print_mutex, NULL))
		return (print_error("Error: print mutex_init\n"));
	if (pthread_mutex_init(&info->eat_mutex, NULL))
		return (print_error("Error: eat mutex_init\n"));
	if (pthread_mutex_init(&info->finish_mutex, NULL))
		return (print_error("Error: finish mutex_init\n"));
	return (0);
}

int	init_philo(t_info *info)
{
	int	i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->num_philo);
	info->forks = malloc(sizeof(t_philo) * info->num_philo);
	info->start_time = get_time();
	if (!info->philo || !info->forks)
		return (print_error("Error: init_philo malloc\n"));
	while (i < info->num_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->num_philo;
		info->philo[i].eat = 0;
		info->philo[i].last_eat_time = info->start_time;
		info->philo[i].info = info;
		i++;
	}
	return (0);
}

int	create_philo(t_info *info)
{
	int	i;

	i = 0;
	if (info->num_philo == 1)
	{
		print_status(&info->philo[0], "has taken a fork");
		ft_sleep(&info->philo[0], info->time_to_die);
		print_status(&info->philo[0], "died");
		check_done(&info->philo[0], 1);
		return (0);
	}
	while (i < info->num_philo)
	{
		if (pthread_create(&info->philo[i].thread, NULL, philo_start, \
			&(info->philo[i])))
			return (print_error("Error: philo thread create\n"));
		i++;
	}
	return (0);
}
