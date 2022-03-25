/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:26:12 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/25 16:44:51 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_enemy
{
	t_vector		pos;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_map{
	char	**mat;
	int		col;
	int		player;
	int		x;
	int		y;
	int		exit;
	int		row;
	int		col;
}	t_map;

int	check_borders(t_map *map);
int	is_in_strings(char c, char *str);
int	check_map(t_map *map);

#endif