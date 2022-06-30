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

typedef struct s_rule{
	int	n_philo;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	time_to_think;
	int	bonus_must_eat;
}	t_rules;

typedef struct s_philo{
	t_rules	*rules;
}	t_philo;

/*
**		UTILS.C
*/
void	init_rules(char **argv, t_philo *philo);
int		check_arguments(t_philo *philo);
int		ft_atoi(const char *str);

#endif