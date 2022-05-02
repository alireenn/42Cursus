/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:26:12 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/14 12:26:57 by anovelli         ###   ########.fr       */
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
# include <time.h>

typedef struct s_win{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_player{
	void	*me1;
	void	*enemy1;
	void	*enemy2;
	void	*exit2;
	void	*exit1;
	void	*coll1;
	void	*coll2;
	void	*pavimento;
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
	int			enemy_mv;
	int			delay;
	int			moves;
	int			can_print;
}	t_map;

typedef enum e_keys
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	K_UP = 126,
	K_DOWN = 125,
	K_LEFT = 123,
	K_RIGHT = 124,
}	t_keys;

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_dir;

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
void	open_image2(t_map *map);
void	sprite_to_screen(t_map *map);
void	enemy_set_image(t_map *map);
int		enemy_delay(t_map *map, int time);
void	enemy_loop(t_map *m);
int		animation(t_map *map);
int		command(int key, t_map *map);
void	set_image(t_map *map, int i, int j);
void	where_am_i(t_map *map);
void	move_up(t_map *map);
char	*ft_itoa(int nb);
int		lenght(int nb, int base);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);
void	esc_porkodyo(t_map *map);
void	esc_porkodyo_temp(t_map *map, char c, char x, int pos);
void	print_moves(t_map *map);
int		control(char *filename);
#endif