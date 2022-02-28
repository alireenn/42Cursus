/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:16:20 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/28 16:06:15 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

t_flag	*new_flag(t_flag *flag)
{
	flag->count = 0;
	return (flag);
}

// int	ft_check_flag(const char *str, int i, t_flag *flag)
// {
// 	while (!ft_strchr("dcsixXpu%", str[++i]))
// 	{
// 		if (str[i] == '.')
// 		{
// 			flag->dot = 1;
// 			while (ft_isdigit(str[i + 1]))
// 			{
// 				flag->prec = (flag->prec * 10) + (str[i + 1] - 48);
// 				i++;
// 			}
// 		}
// 		else if (str[i] == '-')
// 			flag->min = 1;
// 		else if (str[i] == ' ')
// 			flag->space = 1;
// 		else if (str[i] == '+')
// 			flag->plus = 1;
// 		else if (str[i] == '#')
// 			flag->hash = 1;
// 		else if (str[i] == '0' && ft_isdigit(str[i - 1]) == 0)
// 			flag->zero = 1;
// 		else if (ft_isdigit(str[i]))
// 			flag->wdt = flag->wdt * 10 + (str[i] - 48);
// 	}
// 	return (i);
// }

int	ft_deno(char *str, int i, t_flag *flag)
{
	if (str[i] == 'c')
		ft_c(va_arg(flag->arg, int), flag);
	else if (str[i] == 's')
		ft_s(va_arg(flag->arg, char *), flag);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_di(va_arg(flag->arg, int), flag);
	else if (str[i] == 'x')
		ft_x(va_arg(flag->arg, unsigned int), flag, "0123456789abcdef");
	else if (str[i] == 'X')
		ft_x(va_arg(flag->arg, unsigned int), flag, "0123456789ABCDEF");
	return (i);
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
			i++;
			i = ft_deno((char *)str, i, flag);
		}
		else
			len += write(1, &str[i], 1);
	}
	va_end(flag->arg);
	len += flag->count;
	free (flag);
	return (len);
}

// #include <limits.h>

// int	main(void)
// {
	// printf("ft_printf: ");
	// fflush(stdout);
	// printf("\t|%d", ft_printf("%s", "diiio"));
	// printf("\n\n");
	// fflush(stdout);
	// printf("   printf: ");
	// printf("\t|%d", printf("%s", "diiio"));
// 	printf("PRINTF: %d\n", printf(" %x ", 16));
// 	printf("FT_PRINTF %d\n", ft_printf(" %x ", 16));
// }
