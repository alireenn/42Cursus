/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:37:00 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/16 16:52:24 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_strlen(char	*s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_space(int n, t_flag *flag)
{
	while (n > 0)
	{
		if (flag->zero)
			ft_putchar('0', flag);
		else
			ft_putchar(' ', flag);
		n--;
	}
}

void	ft_putstr(char *str, t_flag *flag)
{
	int	len;

	if (str)
	{
		len = ft_strlen(str);
		if (flag->point && flag->accuracy < len && flag->type == 's')
			len = flag->accuracy;
		write(1, str, len);
		flag->counter += len;
	}
}

int	get_hex(unsigned long n)
{
	int	r;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	r = 0;
	while (n)
	{
		r++;
		n /= 16;
	}
	return (r);
}

void	putnbr_p(unsigned long n, t_flag *flag)
{
	char	r[18];
	int		i;

	i = 1;
	while (n)
	{
		r[i] = LOWER[n % 16];
		n = n / 16;
		i++;
	}
	i--;
	if (i)
		ft_putstr("0x", flag);
	while (i)
	{
		ft_putchar(r[i], flag);
		i--;
	}
}
