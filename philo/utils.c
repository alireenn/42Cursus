/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:57:35 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/30 12:58:42 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_arguments(t_philo *philo)
{
	if (philo->rules->n_philo < 1 || philo->rules->time_to_die < 1
	|| philo->rules->time_to_eat < 1 || philo->rules->time_to_sleep < 1
	|| philo->rules->bonus_must_eat < 1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (res);
}

void	init_rules(char **argv, t_philo *philo)
{
	philo->rules = malloc(sizeof(t_rules));
	philo->rules->n_philo = ft_atoi(argv[1]);
	philo->rules->time_to_die = ft_atoi(argv[2]);
	philo->rules->time_to_eat = ft_atoi(argv[3]);
	philo->rules->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->rules->bonus_must_eat = ft_atoi(argv[5]);
}

void	init_philo(t_all *all)
{
	int	i;
	int	j;

	all->philo = malloc(sizeof(t_philo) * (all->philo->rules->n_philo + 1));
	i = 0;
	j = 1;
	while (j < all->philo->rules->n_philo)
	{
		fill_philo_struct(all, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_philo_struct(all, i, j);
}

void	fill_philo_struct(t_all *all, int i, int j)
{
	all->philo[i].id = i + 1;
	all->philo[i].num_of_times_ate = 0;
	all->philo[i].rules->bonus_must_eat = 0;
	all->philo[i].fork.left = i;
	all->philo[i].fork.right = j;
}


