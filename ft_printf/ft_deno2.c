/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deno2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:36:34 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/16 18:16:14 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.c"

char	*ft_hex(char *s, va_list args, t_flag *flag)
{
	long long	n;
	int			tp;

	n = (long long)va_arg(args, unsigned int);
	tp = get_hex(n);
	if (((flag->plus || flag->space) && n >= 0) || n < 0)
		tp++;
	if (flag->accuracy > tp)
		tp = flag->accuracy + 1;
	if (flag->point && flag->accuracy == 0 && n == 0)
		tp = 0;
	prehex(s, n, tp, flag);
	putnbr_hex(*s, n, flag);
	if (flag->width && flag->minus)
		print_space(flag->width - tp, flag);
	return (++s);
}
