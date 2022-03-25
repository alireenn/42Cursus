/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:57 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/25 18:15:49 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	void	*prova;
	int		size;

	if (ac != 3)
		return (0);
	size = 64;
	map.mat = mlx_init();
	if (!map.mat)
		return (NULL);
	mlx_win = mlx_new_window(mlx, map.row, map.col, "So Long!");
	// prova = mlx_xpm_file_to_image(mlx, "images/me1cattiva.xpm", &size, &size);
	// mlx_put_image_to_window(mlx, mlx_win, prova, 1 * 64, 1 * 64);
	// for(int j = 1; j < 1920; j += 17)
	// 	for(int i = 1; i < 1080; i += 17)
	// 		mlx_put_image_to_window(mlx, mlx_win, prova, j, i);
	mlx_loop(mlx);
}
