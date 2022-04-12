/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:26:12 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/07 18:39:30 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_win{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_player{
	void	*morte1;
	void	*morte2;
	void	*morte3;
	void	*morte4;
	void	*morte5;
	void	*me1;
	void	*me2;
	void	*enemy1;
	void	*enemy2;
	void	*exit2;
	void	*exit1;
	void	*coll1;
	void	*coll2;
}	t_player;

typedef struct s_map{
	t_win		win;
	char		**mat;
	t_player	p;
	void		*sfondo;
	int			player;
	int			x;
	int			y;
	int			exit;
	int			row;
	int			col;
	int			coll;
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
int		close_windows(t_map *map);
void	open_image(t_map *map);
void	wall_to_screen(t_map *map);
void	open_image2(t_map *map);
void	coin_to_screen(t_map *map);
void	exit_to_screen(t_map *map);

#endif