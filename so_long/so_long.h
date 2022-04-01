/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:26:12 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/01 18:25:28 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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
	int		player;
	int		x;
	int		y;
	int		exit;
	int		row;
	int		col;
}	t_map;

int		check_borders(t_map *map);
int		is_in_string(char c, char *str);
int		check_map(t_map *map);
int		open_map(char *av, t_map *map);
void	check_char(char c, t_map *map);
void	per_lo_spazio(int fd, t_map *map);
void	helper(char *new_a, int i);
char	*get_next_line(int fd);

#endif