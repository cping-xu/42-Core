/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:12:15 by cping-xu          #+#    #+#             */
/*   Updated: 2023/02/18 12:11:37 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				eat;
	int				left_fork;
	int				right_fork;
	long long		last_eat_time;
	struct s_info	*info;
	pthread_t		thread;
}					t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				num_full_philo;
	int				finish;
	long long		start_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	finish_mutex;
}					t_info;

int			print_error(char *str);
int			ft_atoi(const char *str);
long long	get_time(void);
void		print_status(t_philo *philo, const char *str);
void		ft_sleep(t_philo *philo, long long ms);

int			init_info(t_info *info, int ac, char **av);
int			init_philo(t_info *info);
int			init_mutex(t_info *info);
int			create_philo(t_info *info);

int			check_dead(t_philo *philo);
int			check_done(t_philo *philo, int temp);
void		*philo_start(void *arg);

int			free_info(t_info *info);
int			free_destroy(t_info *info);
void		join_free_destroy(t_info *info);
void		destroy(t_info *info);

#endif
