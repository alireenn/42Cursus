/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:57 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/14 13:12:28 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_windows(t_map *map)
{
	mlx_destroy_window(map->win.mlx, map->win.win);
	free_matrix(map->mat);
	exit(0);
}

void	init(t_map *map)
{
	map->player = 0;
	map->y = 0;
	map->x = 0;
	map->col = 0;
	map->exit = 0;
	map->row = 0;
	map->coll = 0;
	map->enemy_mv = 0;
	map->delay = 0;
	map->moves = 0;
	map->can_print = 1;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		oh_errors("Uso corretto: ./so_long <mappa>", &map, 0);
	if (!control(av[1]))
		oh_errors("la mappa ha un formato sbagliato", &map, 0);
	map.win.mlx = mlx_init();
	if (!map.win.mlx)
		oh_perrors(&map, 0);
	init(&map);
	open_map(av[1], &map);
	check_all(&map);
	map.win.win = mlx_new_window(map.win.mlx, map.col * 64, \
		(map.row + 1) * 64, "So Long!");
	open_image(&map);
	where_am_i(&map);
	mlx_hook(map.win.win, 17, 0, close_windows, &map);
	mlx_hook(map.win.win, 2, 1L << 0, command, &map);
	mlx_loop_hook(map.win.mlx, animation, &map);
	mlx_loop(map.win.mlx);
}
