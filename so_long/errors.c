/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:30:51 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/01 18:37:24 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	while (str[i])
	{
		write(1, &str[i], 1)
		i++;
	}
}

void	oh_errors(void)
{
	ft_putstr("Error");
	exit();
}

void	oh_perrors(void)
{
	ft_putstr("Error");
	exit();
}
