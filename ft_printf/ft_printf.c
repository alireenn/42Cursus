/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:16:20 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/18 18:28:34 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

t_flag	*new_flag(t_flag *flag)
{
	flag->dot = 0;
	flag->min = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->plus = 0;
	flag->wdt = 0;
	flag->prec = 0;
	flag->hash = 0;
	flag->count = 0;
	flag->sign = 0;
	flag->isneg = 0;
	return (flag);
}

int	ft_con_le_mani_flag(const char *str, int i, t_flag *flag)
{
	while (!ft_strchr("dcsixXpu%", str[++i]))
	{
		if (str[i] == '.')
		{
			flag->dot = 1;
			while (ft_isdigit(str[i + 1]))
			{
				flag->prec = (flag->prec * 10) + (str[i + 1] - 48);
				i++;
			}
		}
		else if (str[i] == '-')
			flag->min = 1;
		else if (str[i] == ' ')
			flag->space = 1;
		else if (str[i] == '+')
			flag->plus = 1;
		else if (str[i] == '#')
			flag->hash = 1;
		else if (str[i] == '0' && ft_isdigit(str[i - 1]) == 0)
			flag->zero = 1;
		else if (ft_isdigit(str[i]))
			flag->wdt = flag->wdt * 10 + (str[i] - 48);
	}
	return (i);
}

int	ft_deno(char *str, int i, t_flag *flag)
{
	while (ft_strchr("diuxXcsp%", str[i + 1]))
	{
		if (str[i] == 'c')
			ft_c(str[i], flag);
		else if (str[i] == 's')
			ft_s(str[i], flag);
	}
}

int	ft_printf(const char *str, ...)
{
	t_flag	*flag;
	int		i;
	int		len;

	i = -1;
	len = 0;
	flag = (t_flag *)malloc(sizeof(t_flag));
	if (!flag)
		return (0);
	flag = new_flag(flag);
	va_start(flag->arg, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i = ft_con_le_mani_flag(str, i, flag);
			i = ft_deno(str, i, flag);
		}
		else
			len += write(1, &str[i], 1);
	}
	va_end(flag->arg);
	len += flag->count;
	free (flag);
	return (len);
}

int	main(void)
{
	ft_printf("%10.15d prova", 6);
	printf("dot %d\n", flag->dot);
	printf("prec %d\n", flag->prec);
	printf("min %d\n", flag->min);
	printf("hash %d\n", flag->hash);
	printf("space %d\n", flag->space);
	printf("plus %d\n", flag->plus);
	printf("zero %d\n", flag->zero);
	printf("wdt %d\n", flag->wdt);
}
