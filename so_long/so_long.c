/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:57 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/12 19:36:18 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_windows(t_map *map)
{
	mlx_destroy_window(map->win.mlx, map->win.win);
	free_matrix(map->mat);
	exit(0);
}

int	main(int ac, char **av)
{
	t_map	map;

	(void) av;
	if (ac != 2)
		oh_errors("Uso corretto: ./so_long <mappa>", &map, 0);
		map.win.mlx = mlx_init();
	if (!map.win.mlx)
		oh_perrors(&map, 0);
	map.player = 0;
	open_map(av[1], &map);
	check_all(&map);
	map.win.win = mlx_new_window(map.win.mlx, map.col * 64, \
		(map.row + 1) * 64, "So Long!");
	map.delay = 0;
	map.moves = 0;
	open_image(&map);
	where_am_i(&map);
	mlx_hook(map.win.win, 17, 0, close_windows, &map);
	mlx_hook(map.win.win, 2, 1L << 0, command, &map);
	mlx_loop_hook(map.win.mlx, animation, &map);
	mlx_loop(map.win.mlx);
}
