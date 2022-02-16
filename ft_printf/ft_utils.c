/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:22:48 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/16 18:18:55 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

char	*nextarg(char *s)
{
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '%')
		{
			s++;
			return (s);
		}
		if (*s == '%')
			s++;
		s++;
	}
	return (s);
}

int	printorigin(char *s, size_t size, t_flag *flag)
{
	size_t	i;

	i = 0;
	while (s[i] && i < size)
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
			{
				ft_putchar('%', flag);
				i++;
			}
		}
		else
			ft_putchar(s[i], flag);
		i++;
	}
	return (0);
}

void	parseflag(char *s, t_flag *flag)
{
	if (*s == '-')
		flag->minus = 1;
	if (*s == '.')
		flag->point = 1;
	if (*s == '#')
		flag->hash = 1;
	if (*s == ' ')
		flag->space = 1;
	if (*s == '+')
		flag->plus = 1;
	if (*s == '0')
		flag->zero = 1;
}

char	*get_flag(char *s, t_flag *flag)
{
	while (!ft_strchr(KEYS, *s))
	{
		parseflag(s, flag);
		if (ft_isdigit(*s) && flag->point)
			flag->accuracy = ft_atoi(s);
		else if (ft_isdigit(*s))
			flag->width = ft_atoi(s);
		while (ft_isdigit(*s) && ft_isdigit(*(s + 1)))
			s++;
		s++;
	}
	if (flag->minus || flag->point)
		flag->zero = 0;
	flag->type = *s;
	return (s);
}

char	*parsearg(char *s, va_list args, t_flag *flag)
{
	if (*s == 'c')
		return (ft_c(s, args, flag));
	else if (*s == 's')
		return (ft_s(s, va_arg(args, char *), flag));
	else if (*s == 'i' || *s == 'd')
		return (ft_di(s, va_arg(args, int), flag));
	else if (*s == 'u')
		return (ft_u(s, args, flag));
	else if (*s == 'p')
		return (ft_p(s, args, flag));
	else if (*s == 'x' || *s == 'X')
		return (ft_hex(s, args, flag));
	else if (*s == '%')
		return (ft_s(s, "%", flag));
	return (s);
}
