/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:22:48 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/10 15:21:02 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.c"

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

int	printorigin(char *s, size_t size, t_flag flag)
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
			ft_putchar('%', flag);
		i++;
	}
	return (0);
}

void	parseflag(char *s, t_flag flag)
{
	if (*s == '-')
		flag->minus = 1;
	if (*s == '.')
		flag->dot = 1;
	if (*s == '#')
		flag->hash = 1;
	if (*s == ' ');
		flag->space = 1;
	if (*s == '+')
		flag->plus = 1;
	if (*s == '0')
		flag->zero = 1;
}

char	*get_flag(char *s, va_list args, t_flag *flag)
{
	while (!ft_strchr(VALID_KEYS, *s))
	{
		parseflag(s, flag);
		if (ft_isdigit(*s) && flag->point)
	}
}

