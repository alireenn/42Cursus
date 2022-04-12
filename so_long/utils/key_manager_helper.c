/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:21:19 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/12 18:26:57 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	del_dyo_kane(t_map *map)
{
	int	i;
	int	j;

	map->coll--;
	if (map->coll != 0)
		return ;
	i = 0;
	while (i < (map->row + 1))
	{
		j = 0;
		while (map->mat[i][j] != '\0')
		{
			if (map->mat[i][j] == 'E')
				mlx_put_image_to_window(map->win.mlx, \
					map->win.win, map->p.exit2, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	move_up(t_map *map)
{	
	if (map->mat[map->x - 1][map->y] == '1')
		return ;
	else if (map->mat[map->x - 1][map->y] == '0')
	{
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, map->x * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.me1, \
			map->y * 64, (map->x - 1) * 64);
	}
	else if (map->mat[map->x - 1][map->y] == 'C')
	{
		map->mat[map->x - 1][map->y] = '0';
		del_dyo_kane(map);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, map->x * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, (map->x - 1) * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.me1, \
			map->y * 64, (map->x - 1) * 64);
	}
	else if ((map->mat[map->x - 1][map->y] == 'N') || \
		(map->mat[map->x - 1][map->y] == 'E'))
		esc_porkodyo_temp(map, map->mat[map->x - 1][map->y], 'x', 1);
	map->x--;
	print_moves(map);
}

void	move_down(t_map *map)
{	
	if (map->mat[map->x + 1][map->y] == '1')
		return ;
	else if (map->mat[map->x + 1][map->y] == '0')
	{
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, map->x * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.me1, \
			map->y * 64, (map->x + 1) * 64);
	}
	else if (map->mat[map->x + 1][map->y] == 'C')
	{
		map->mat[map->x + 1][map->y] = '0';
		del_dyo_kane(map);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, map->x * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, (map->x + 1) * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.me1, \
			map->y * 64, (map->x + 1) * 64);
	}
	else if ((map->mat[map->x + 1][map->y] == 'N') || \
		(map->mat[map->x + 1][map->y] == 'E'))
		esc_porkodyo_temp(map, map->mat[map->x + 1][map->y], 'x', 0);
	map->x++;
	print_moves(map);
}

void	move_left(t_map *map)
{	
	if (map->mat[map->x][map->y - 1] == '1')
		return ;
	else if (map->mat[map->x][map->y - 1] == '0')
	{
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, map->x * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.me1, \
			(map->y - 1) * 64, map->x * 64);
	}
	else if (map->mat[map->x][map->y - 1] == 'C')
	{
		map->mat[map->x][map->y - 1] = '0';
		del_dyo_kane(map);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, map->x * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			(map->y - 1) * 64, (map->x) * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.me1, \
			(map->y - 1) * 64, (map->x) * 64);
	}
	else if ((map->mat[map->x][map->y - 1] == 'N') || \
		(map->mat[map->x][map->y - 1] == 'E'))
		esc_porkodyo_temp(map, map->mat[map->x][map->y - 1], 'y', 1);
	map->y--;
	print_moves(map);
}

void	move_right(t_map *map)
{	
	if (map->mat[map->x][map->y + 1] == '1')
		return ;
	else if (map->mat[map->x][map->y + 1] == '0')
	{
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, map->x * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.me1, \
			(map->y + 1) * 64, map->x * 64);
	}
	else if (map->mat[map->x][map->y + 1] == 'C')
	{
		map->mat[map->x][map->y + 1] = '0';
		del_dyo_kane(map);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			map->y * 64, map->x * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.pavimento, \
			(map->y + 1) * 64, (map->x) * 64);
		mlx_put_image_to_window(map->win.mlx, map->win.win, map->p.me1, \
			(map->y + 1) * 64, (map->x) * 64);
	}
	else if ((map->mat[map->x][map->y + 1] == 'N') || \
		(map->mat[map->x][map->y + 1] == 'E'))
		esc_porkodyo_temp(map, map->mat[map->x][map->y + 1], 'y', 0);
	map->y++;
	print_moves(map);
}
