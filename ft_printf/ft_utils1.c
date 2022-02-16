/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:41:53 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/15 21:44:35 by anovelli         ###   ########.fr       */
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

int	ft_atoi(const char *s)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (get_digit(s[i]))
	{
		result = result * 10;
		result = result + s[i] - 48;
	}
	return (result);
}

int	get_digit(long long n)
{
	int	r;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	r = 0;
	if (n < 0)
		r = 1;
	while (n)
	{
		r++;
		n /= 10;
	}
	return (r);
}

void	prepare_int(int num, int tp, t_flag *flag)
{
	if (num < 0 && (flag->zero && !flag->point))
		ft_putchar('-', flag);
	if (flag->width && !flag->minus)
		print_space(flag->width - tp, flag);
	if (num < 0 && (!flag->zero && flag->point))
		ft_putchar('-', flag);
	if (flag->plus && num >= 0)
		ft_putchar('+', flag);
	if (flag->space && num >= 0 && !flag->plus)
		ft_putchar(' ', flag);
	if (flag->accuracy > get_digit(num))
		print_zero(flag->accuracy - get_digit(num), flag);
}
