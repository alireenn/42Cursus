/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:48:08 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/07 21:25:59 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	allzero(t_flag *flag)
{
	flag->dot = 0;
	flag->min = 0;
	flag->hash = 0;
	flag->plus = 0;
	flag->prec = 0;
	flag->space = 0;
	flag->wdt = 0;
	flag->zero = 0;
}

char	*checkflags(char *str, t_flag *flag)
{
	while (str++)
	{
		if ((char)str == '+')
			flag->plus = 1;
		else if ((char)str == '-')
			flag->min = 1;
		else if ((char)str == '.')
		{
			flag->dot = 1;
			precision(str++);
		}
		else if ((char)str == '#')
			flag->hash = 1;
		else if ((char)str == '0')
			flag->zero = 1;
		else if ((char)str == ' ')
			flag->space = 1;
	}
	return (str);
}

char	*copy(const char *str, char *s1)
{
	while (*str)
	{
		*s1 = *str;
		s1++;
		str++;
	}
	return (s1);
}
