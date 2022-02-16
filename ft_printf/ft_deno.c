/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deno.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:33:18 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/16 18:13:27 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

char	*ft_c(char *s, va_list args, t_flag *flag)
{
	char	c;

	c = va_arg(args, int);
	if (flag->width && !flag->minus)
	{
		print_space(flag->width - 1, flag);
		ft_putchar(c, flag);
	}
	else if (flag->width && flag->minus)
	{
		ft_putchar(c, flag);
		print_space(flag->width - 1, flag);
	}
	else
		ft_putchar(c, flag);
	s++;
	return (s);
}

char	*ft_s(char *s, char *arg, t_flag *flag)
{
	int	len;

	len = ft_strlen(arg);
	if (arg == NULL)
		len = 6;
	if (flag->point && flag->accuracy < len)
		len = flag->accuracy;
	if (flag->width && !flag->minus)
		print_space(flag->width - len, flag);
	if (arg != NULL)
		ft_putstr(arg, flag);
	else
		ft_putstr("(null)", flag);
	if (flag->width && flag->minus)
		print_space(flag->width - len, flag);
	s++;
	return (s);
}

char	*ft_di(char *s, int num, t_flag *flag)
{
	int	tp;

	tp = get_digit(num);
	if (((flag->plus || flag->space) && num >= 0) || num < 0)
		tp++;
	if (num < 0 && flag->accuracy >= tp)
		tp = flag->accuracy + 1;
	if (flag->accuracy > tp)
		tp = flag->accuracy;
	if (flag->point && flag->accuracy == 0 && num == 0)
		tp = 0;
	prepare_int(num, tp, flag);
	ft_putnbr(num, flag);
	if (flag->width && flag->minus)
		print_space(flag->width - tp, flag);
	return (++s);
}

char	*ft_u(char *s, va_list args, t_flag *flag)
{
	unsigned int	num;
	int				tp;

	num = va_arg(args, unsigned int);
	tp = get_digit(num);
	if (flag->plus || flag->space)
		tp++;
	if (flag->accuracy > tp)
		tp = flag->accuracy;
	if (flag->point && flag->accuracy == 0 && num == 0)
		tp = 0;
	if (flag->width && !flag->minus)
		print_space(flag->width - tp, flag);
	if (flag->plus)
		ft_putchar('+', flag);
	if (flag->space && !flag->plus)
		ft_putchar(' ', flag);
	if (flag->accuracy > get_digit(num))
		print_zero(flag->accuracy - get_digit(num), flag);
	ft_putnbr(num, flag);
	if (flag->width && flag->minus)
		print_space(flag->width - tp, flag);
	s++;
	return (s);
}

char	*ft_p(char *s, va_list args, t_flag *flag)
{
	void	*p;
	int		tp;

	p = va_arg(args, void *);
	tp = get_hex((unsigned long)p);
	if (flag->plus || flag->space)
		tp++;
	if (flag->accuracy > tp)
		tp = flag->accuracy;
	if (flag->width && !flag->minus)
		print_space(flag->width - tp - 2, flag);
	if (p == 0)
		ft_putstr("0x0", flag);
	else
		putnbr_p((unsigned long)p, flag);
	if (flag->width && flag->minus)
		print_space(flag->width - tp - 2, flag);
	s++;
	return (s);
}
