/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:11:10 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/05 20:10:15 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_image(t_map *map)
{
	int	a;
	int	b;
	int	i;
	int	j;

	i = 0;
	map->sfondo = mlx_xpm_file_to_image(map->win.mlx, \
			"images/sfondoprovvisorio.xpm", &a, &b);
	mlx_put_image_to_window(map->win.mlx, map->win.win, map->sfondo, 0, 0);
	printf("%d || %d\n",  map->col, map->row);
	while (i < map->col)
	{
		j = 0;
		while (j < map->row)
		{
			printf("%d || %d || %c\n", j, i, map->mat[j][i]);
			if (map->mat[j][i] == 1){
				mlx_put_image_to_window(map->win.mlx, map->win.win, map->sfondo, i, j);
				printf("%d || %d\n", j, i);}
			j++;
		}
		i++;
	}
}
