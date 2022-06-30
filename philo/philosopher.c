/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:52:09 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/30 12:59:49 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	int	ret;

	philo = malloc(sizeof(t_philo));
	if (argc != 5 && argc != 6)
		return (printf("Wrong amount of arguments\n"));
	init_rules(argv, philo);
	ret = check_arguments(philo);
	if (ret == 0)
		return (printf("wrong arguments"));

	printf("%d\n", philo->rules->n_philo);
	printf("%d\n", philo->rules->time_to_die);
	printf("%d\n", philo->rules->time_to_eat);
	printf("%d\n", philo->rules->time_to_sleep);
	if (argv[5])
		printf("%d\n", philo->rules->bonus_must_eat);
	
}