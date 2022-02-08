/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:48:08 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/08 03:36:37 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	flag->len = 0;
}

void	reset_zero(t_flag *flag)
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

int	checkflags(const char *str, t_flag *flag, int i)
{
	while (!ft_strchr("udcspixX%", str[++i]))
	{
		if (str[i] == '+')
			flag->plus = 1;
		else if (str[i] == '-')
			flag->min = 1;
		else if (str[i] == '.')
		{
			flag->dot = 1;
			while (ft_isdigit(str[i + 1]))
			{
				flag->prec = (flag->prec * 10) + (str[i + 1] - 48);
				i++;
			}
		}
		else if (str[i] == '#')
			flag->hash = 1;
		else if (str[i] == '0' && ft_isdigit(str[i] - 1) == 0)
			flag->zero = 1;
		else if (str[i] == ' ')
			flag->space = 1;
		else if (ft_isdigit(str[i]))
			flag->wdt = (flag->wdt * 10) + (str[i] - 48);
	}
	return (i);
}

void	checkdeno(const char *str, t_flag *flag, int i)
{
	if (str[i] == 'c')
		ft_c(flag);
	// else if (str[i] == 's')
	// 	ft_s(flag);
	// else if (str[i] == 'u')
	// 	ft_u(flag);
	// else if (str[i] == 'p')
	// 	ft_p(flag);
	// else if (str[i] == 'd' || str[i] == 'i')
	// 	ft_di(flag);
	// else if (str[i] == 'x')
	// 	ft_x(flag);
	// else if (str[i] == 'X')
	// 	ft_X(flag);
	else if (str[i] == '%')
		flag->len += write(1, "%", 1);
	reset_zero(flag);
}
