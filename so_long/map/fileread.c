/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:24:27 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/05 18:16:43 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	per_lo_spazio(int fd, t_map *map)
{
	char	*s;
	int		line;

	line = 0;
	s = get_next_line(fd);
	while (s)
	{
		if (s[0] != '\0')
			line++;
		free(s);
		s = get_next_line(fd);
	}
	map->row = line;
	map->mat = malloc(sizeof(char *) * line + 1);
	if (!map->mat)
		oh_perrors(map, 0);
}

int	open_map(char *av, t_map *map)
{
	int		fd;
	char	*s;
	int		i;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		oh_perrors(map, 0);
	per_lo_spazio(fd, map);
	close(fd);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		oh_perrors(map, 0);
	i = -1;
	s = get_next_line(fd);
	while (s)
	{
		if (s[0] != '\0')
			map->mat[++i] = s;
		s = get_next_line(fd);
	}
	map->mat[++i] = 0;
	if (!map->mat[0])
		oh_perrors(map, 1);
	return (1);
}
