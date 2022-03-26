/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:24:27 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/26 17:09:52 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map(char c, t_map *map)
{
	if (c == 'E')
		map->exit = 1;
	else if (c == 'P')
		map->player = 1;
	else if (c == 'C')
		map->col = 1;
}

void	per_lo_spazio(int fd, t_map *map)
{
	char	*c;
	int		i;
	int		r;

	r = 0;
	c = 0;
	c = get_next_line(fd);
	while (c)
	{
		i = 0;
		while (c[i])
		{
			check_map(c[i], map);
			i++;
		}
		free(c);
		c = get_next_line(fd);
		if (s[0] != '\0')
			r++;
	}
	map->row = r;
	map->mat = malloc(sizeof(char *) * r + 1);
}

int	open_map(char *av, t_map *map)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	per_lo_spazio(fd, map);

}
