/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:48:08 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/07 20:35:24 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

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
}

void checkflags(const char **str, t_flag *flag)
{
	if (*str + 1 == '+')
		flag->plus = 1;
	if (*str + 1 == '-')
		flag->min = 1;
		
}