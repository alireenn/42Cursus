/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:30 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/08 05:53:26 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_flag	*flag;
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	flag = malloc(sizeof(t_flag));
	if (!flag)
		return (0);
	va_start(flag->arg, str);
	allzero(flag);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i = checkflags(str, flag, i);
			checkdeno(str, flag, i);
		}
		else
			ret += write(1, &str[i], 1);
	}
	va_end(flag->arg);
	ret += flag->len;
	free(flag);
	return (ret);
}

int main()
{
	int d=5;
	//printf("%%");
	ft_printf("111%10c222%-5c333%3c444\n", 'a', 'b', 'c');
}
