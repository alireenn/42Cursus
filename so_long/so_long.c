/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:57 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/05 16:04:38 by anovelli         ###   ########.fr       */
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
	//void	*win;

	(void) av;
	if (ac != 2)
		oh_errors("Uso corretto: ./so_long <mappa>", &map, 0);
	map.win.mlx = mlx_init();
	if (!map.win.mlx)
		return (printf("Cazzo\n"));
	open_map(av[1], &map);
	check_all(&map);
	map.win.win = mlx_new_window(map.win.mlx, map.row * 64, map.col * 64, "So Long!");
	// mlx_hook(map.win.win, 17, 0, close_windows, &map);
	mlx_loop(map.win.mlx);
	// printf("%d\n", check_borders(&map));
	// map.mat = mlx_init();
	// if (!map.mat)
	// 	return (0);
	// open_map(av[1], map);
	// mlx_win = mlx_new_window(mlx, map.row, map.col, "So Long!");

	// prova = mlx_xpm_file_to_image(mlx, "images/me1cattiva.xpm", &size, &size);
	// mlx_put_image_to_window(mlx, mlx_win, prova, 1 * 64, 1 * 64);
	// for(int j = 1; j < 1920; j += 17)
	// 	for(int i = 1; i < 1080; i += 17)
	// 		mlx_put_image_to_window(mlx, mlx_win, prova, j, i);
	// mlx_loop(mlx);
}
