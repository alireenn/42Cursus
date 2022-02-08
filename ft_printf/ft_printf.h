/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:35 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/08 05:51:47 by anovelli         ###   ########.fr       */
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
# include "./libft/libft.h"

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
	int		perc;
	int		len;
	va_list	arg;
}	t_flag;

int		ft_printf(const char *str, ...);
void	allzero(t_flag *flag);
int		checkflags(const char *str, t_flag *flag, int i);
char	*copy(const char *str, char *s1);
int		ft_isdigit(int c);
void	checkdeno(const char *str, t_flag *flag, int i);
void	reset_zero(t_flag *flag);
void	ft_c(t_flag *flag);

#endif