/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:30:51 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/14 12:47:20 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	oh_errors(char *str, t_map *map, int ci_sta)
{
	ft_putstr("Error: ");
	ft_putstr(str);
	if (ci_sta)
		free_matrix(map->mat);
	exit(0);
}

void	oh_perrors(t_map *map, int ci_sta)
{
	perror("Error");
	if (ci_sta)
		free_matrix(map->mat);
	exit(0);
}
