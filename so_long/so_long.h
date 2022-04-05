/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:26:12 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/05 14:39:40 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include "mlx/mlx.h"

typedef struct s_win{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_map{
	t_win	win;
	char	**mat;
	int		player;
	int		x;
	int		y;
	int		exit;
	int		row;
	int		col;
	int		coll;
}	t_map;

int		check_borders(t_map *map);
int		is_in_string(char c, char *str);
int		check_map(t_map *map);
int		open_map(char *av, t_map *map);
void	check_char(char c, t_map *map);
void	per_lo_spazio(int fd, t_map *map);
void	helper(char *new_a, int i);
char	*get_next_line(int fd);
void	oh_errors(char *str, t_map *map, int ci_sta);
void	oh_perrors(t_map *map, int ci_sta);
void	check_all(t_map *map);
void	free_matrix(char **matrix);

#endif