/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deno.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:17:52 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/18 18:31:06 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_c(char c, t_flag flag)
{
	int	i;

	i = 0;
	if (flag->wdt && !flag->min)
	{
		while (i != flag->wdt)
			write (1, ' ', 1);
		write (1, &c, 1);
		flag->len++;
	}
	else if (flag->wdt && flag->min)
	{
		write (1, &c, 1);
		while (i != flag->wdt)
			write (1, ' ', 1);
		flag->len++;
	}
	else if (!flag->wdt)
		flag->len += write(1, &c, 1);
	return (c);
}
