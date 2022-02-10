/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:41:53 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/10 14:50:53 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putchar(char c, t_flag *flag)
{
	write(1, &c, 1);
	flag->counter++;
}

char	*ft_strchr(const char *s, int ch)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return (&str[i]);
		i++;
	}
	if ((char)ch == '\0')
		return (&str[i]);
	return (NULL);
}
