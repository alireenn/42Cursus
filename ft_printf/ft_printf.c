/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:30 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/07 21:22:20 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_flag	*flag;
	int		ret;
	char	*s1;

	ret = 0;
	s1 = copy(str, s1);
	flag = malloc(sizeof(t_flag));
	if (!flag)
		return (0);
	va_start(flag->arg, str);
	allzero(flag);
	while (*str)
	{
		if (*str == '%')
		{
			printf("sono entrato\n");
			checkflags(s1, flag);
		}
		else
			ret = ret + write(1, &(*str), 1);
		str++;
	}
	return (ret);
}

int main()
{
	int d=5;
	//printf("%%");
	printf("test: (");
	printf("%+-9.06d)\n", d);
	//ft_printf("ciaooo");
}