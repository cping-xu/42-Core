/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:12:03 by cping-xu          #+#    #+#             */
/*   Updated: 2023/02/16 00:58:16 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_info(t_info *info)
{
	free(info->philo);
	free(info->forks);
	return (0);
}

int	free_destroy(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free_info(info);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	return (0);
}

void	join_free_destroy(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
	free_destroy(info);
}

void	destroy(t_info *info)
{
	int	i;
	int	temp;

	temp = 1;
	while (temp)
	{
		i = 0;
		info->num_full_philo = 0;
		while (i < info->num_philo)
		{
			if (temp && check_dead(&info->philo[i]))
				temp = 0;
			i++;
		}
		usleep(10);
	}
	join_free_destroy(info);
}
