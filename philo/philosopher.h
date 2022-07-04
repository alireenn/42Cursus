/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:52:20 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/30 12:59:23 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

typedef struct s_rule{
	int	n_philo;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	time_to_think;
	int	bonus_must_eat;
}	t_rules;

typedef struct s_fork
{
	int				left;
	int				right;
}					t_fork;

typedef struct s_philo{
	t_rules		*rules;
	int			num_of_times_ate;
	long long	time_to_die;
	int			id;
	t_fork		fork;
	pthread_t	thread;
}	t_philo;

typedef struct s_all
{
	int				n_thread;
	int				philo_dead;
	long long		t0;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}					t_all;

/*
**		UTILS.C
*/
void	init_rules(char **argv, t_philo *philo);
int		check_arguments(t_philo *philo);
int		ft_atoi(const char *str);
void	fill_philo_struct(t_all *all, int i, int j);

#endif