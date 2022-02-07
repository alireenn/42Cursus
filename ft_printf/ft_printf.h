/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:35 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/07 20:17:47 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_flag
{
	int		min;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		prec;
	int		wdt;
	va_list	arg;
}	t_flag;

int		ft_printf(const char *str, ...);
void	allzero(t_flag *flag);
void	checkflags(const char **str, t_flag *flag);

#endif