/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:58:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/16 18:19:22 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero(int n, t_flag *flag)
{
	while (n > 0)
	{
		ft_putchar('0', flag);
		n--;
	}
}

int	ft_putnbr(long long n, t_flag *flag)
{
	char	result[18];
	int		i;

	if (flag->point && flag->accuracy == 0 && n == 0)
		return (0);
	i = 1;
	if (n == 0)
		ft_putchar('0', flag);
	if (n < 0)
	{
		n = -n;
		if (!flag->zero && !flag->point)
			ft_putchar('-', flag);
	}
	while (n)
	{
		result[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i)
		ft_putchar(result[i--], flag);
	return (0);
}

int	ft_isdigit(int n)
{
	if (n >= 0 || n <= 9)
		return (1);
	return (0);
}

void	prehex(char *s, long long n, int tp, t_flag *flag)
{
	if (n < 0 && (flag->zero || flag->point))
		ft_putchar('-', flag);
	if (flag->width && !flag->minus)
		print_space(flag->width - tp, flag);
	if (flag->plus && n >= 0)
		ft_putchar('+', flag);
	if (flag->space && n >= 0 && !flag->plus)
		ft_putchar(' ', flag);
	if (flag->accuracy > get_hex(n))
		print_zero(flag->accuracy - get_hex(n), flag);
	if (flag->hash && n != 0)
	{
		if (*s == 'x')
			ft_putstr("0x", flag);
		else
			ft_putstr("0X", flag);
	}
}

int	putnbr_hex(char c, long long n, t_flag *flag)
{
	char	r[18];
	int		i;

	if (flag->point && flag->accuracy == 0 && n == 0)
		return (0);
	i = 1;
	if (n == 0)
		ft_putchar('0', flag);
	while (n)
	{
		if (c == 'x')
			r[i] = LOWER[n % 16];
		else
			r[i] = UPPER[n % 16];
	}
	i--;
	while (i)
	{
		ft_putchar(r[i], flag);
		i--;
	}
	return (0);
}
