/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:08:08 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/10 14:45:31 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

t_flag	*new_flag(void)
{
	t_flag	flag;

	flag = malloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->type = '\0';
	flag->hash = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->point = 0;
	flag->accuracy = 0;
	flag->space = 0;
	flag->uppercase = 0;
	flag->width = 0;
	flag->zero = 0;
	return (flag);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*s
	char	*temp;
	t_flag	*flag;

	s = (char *)str;
	va_startt(args, str);
	flag = new_flag();
	while (*s)
	{
		temp = s;
		s = nextarg(s);
		printorigin(temp, s - temp, flag);
		s = get_flag(s, flag, args);
	}
}
