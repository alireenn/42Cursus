/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:26:35 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/09 18:50:36 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_c(t_flag *flag)
{
	char	c;
	char	*str;

	c = va_arg(flag->arg, int);
	flag->len += 1;
	if (flag->wdt > 1)
	{
		str = ft_memset(malloc(flag->wdt), 32, flag->wdt - 1);
		if (flag->min == 0)
		{
			ft_putstr_fd(str, 1);
			write(1, &c, 1);
		}
		else
		{
			write(1, &c, 1);
			ft_putstr_fd(str, 1);
		}
		free(str);
		flag->len += flag->wdt - 1;
	}
	else
		write(1, &c, 1);
}

void	ft_s(t_flag *flag)
{
	int		c;
	char	*str;

	c = va_arg(flag->arg, int);
	if (flag->wdt > 1)
	{
		str = ft_memset(malloc(flag->wdt), 32, flag->wdt - 1);
		if (flag->min == 0)
		{
			ft_putstr_fd(str, 1);
			write(1, &c, 1);
		}
		else
		{
			write(1, &c, 1);
			ft_putstr_fd(str, 1);
		}
		free(str);
		flag->len += flag->wdt - 1;
	}
	else
		write(1, &c, 1);
}

void	ft_di(t_flag *flag)
{
	int		d;
	char	*str;

	d = va_arg(flag->arg, int);
	str = ft_memset(malloc(flag->wdt), 32, flag->wdt - 1);
		flag->len += 1;
	if (flag->wdt > 1)
	{
		str = ft_memset(malloc(flag->wdt), 32, flag->wdt - 1);
		if (flag->min == 0)
		{
			ft_putstr_fd(str, 1);
			ft_putnbr(d);
		}
		else
		{
			ft_putnbr(d);
			ft_putstr_fd(str, 1);
		}
		free(str);
		flag->len += flag->wdt - 1;
	}
	else
		ft_putnbr(d);
}

