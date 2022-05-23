/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:11:03 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/23 16:44:32 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*nextline(char *save)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!temp)
		return (NULL);
	i += 1;
	j = 0;
	while (save[i])
		temp[j++] = save[i++];
	temp[j] = 0;
	free(save);
	return (temp);
}

char	*findnl(char *save)
{
	unsigned int		i;
	char				*ret;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		ret[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		ret[i] = '\n';
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_save(int fd, char *save)
{
	char	*buf;
	int		i;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(save, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(save);
			free(buf);
			return (NULL);
		}
		buf[i] = 0;
		if (!save)
			save = buf;
		else
			save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	save[fd] = ft_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	ret = findnl(save[fd]);
	save[fd] = nextline(save[fd]);
	return (ret);
}
