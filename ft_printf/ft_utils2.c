/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:42:31 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/28 17:11:38 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_helper(unsigned long long x, t_flag *flag)
{
	const char	base[] = "0123456789abcdef";

	if (x < 16)
	{
		if (x <= 9)
		{
			ft_putchar(x + '0', flag);
			return ;
		}
		ft_putchar(base[x % 16], flag);
		return ;
	}
	else
	{
		ft_p_helper(x / 16, flag);
		ft_putchar(base[x % 16], flag);
	}
}

void	ft_p(unsigned long long x, t_flag *flag)
{
	flag->count += write(1, "0x", 2);
	ft_p_helper(x, flag);
}
