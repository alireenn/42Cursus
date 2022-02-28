/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deno.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:17:52 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/28 15:29:48 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(int c, t_flag *flag)
{
	flag->count += write(1, &c, 1);
}

void	ft_s(char *str, t_flag *flag)
{
	if (!str)
	{
		ft_s("(null)", flag);
		return ;
	}
	while (*str)
	{
		ft_c(*str, flag);
		str++;
	}
}

void	ft_di(int n, t_flag *flag)
{
	if (n == -2147483648)
	{
		ft_putchar('-', flag);
		ft_putchar('2', flag);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', flag);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0', flag);
		return ;
	}
	else
		ft_di(n / 10, flag);
	ft_di(n % 10, flag);
}

void	ft_x(unsigned int x, t_flag *flag, char *base)
{
	if (x < 16)
	{
		if (x <= 9)
		{
			ft_putchar(x + '0', flag);
			return ;
		}
		ft_putchar(base[x % 16], flag);
		return ;
	}
	else
	{
		ft_x(x / 16, flag);
		ft_putchar(base[x % 16], flag);
	}
}
// s d i u x X c p 

// s = putstring
// c = putchar (o write)
// p x X = putnbr con base 16
// u 
// d i = putint (putnbr base 10)