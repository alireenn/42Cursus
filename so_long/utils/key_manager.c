/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:58:23 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/14 13:16:04 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	esc_porkodyo(t_map *map)
{
	mlx_destroy_window(map->win.mlx, map->win.win);
	free_matrix(map->mat);
	exit(0);
}

void	esc_porkodyo_temp(t_map *map, char c, char x, int pos)
{
	if (c == 'N')
	{
		ft_putstr("Hai perso\n");
		esc_porkodyo(map);
	}
	if (c == 'E' && map->coll == 0)
	{
		ft_putstr("Hai vinto\n");
		esc_porkodyo(map);
	}
	if (c == 'E' && map->coll != 0)
	{
		if (x == 'x' && pos)
			map->x++;
		else if (x == 'x' && !pos)
			map->x--;
		else if (x == 'y' && pos)
			map->y++;
		else if (x == 'y' && !pos)
			map->y--;
		map->can_print = 0;
	}
}

int	command(int key, t_map *map)
{
	if (key == ESC)
		esc_porkodyo(map);
	if (key == K_UP || key == W)
		move_up(map);
	if (key == K_DOWN || key == S)
		move_down(map);
	if (key == K_LEFT || key == A)
		move_left(map);
	if (key == K_RIGHT || key == D)
		move_right(map);
	return (0);
}

void	print_moves(t_map *map)
{
	char	*s;

	if (!map->can_print)
	{
		map->can_print = 1;
		return ;
	}
	s = ft_itoa(map->moves);
	mlx_string_put(map->win.mlx, map->win.win, 10, 15, 0x0, "MOVES: ");
	mlx_string_put(map->win.mlx, map->win.win, 80, 15, 0x0, s);
	free(s);
	map->moves++;
	s = ft_itoa(map->moves);
	set_image(map, 0, 1);
	set_image(map, 0, 0);
	mlx_string_put(map->win.mlx, map->win.win, 10, 15, 16777215, "MOVES: ");
	ft_putstr("Moves: ");
	mlx_string_put(map->win.mlx, map->win.win, 80, 15, 16777215, s);
	ft_putstr(s);
	ft_putchar('\n');
	free(s);
}
