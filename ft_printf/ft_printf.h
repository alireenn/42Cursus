/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:00:04 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/18 18:25:56 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h> 
# include <stdio.h>

typedef struct s_flag
{
	int		dot;
	int		min;
	int		space;
	int		zero;
	int		wdt;
	int		plus;
	int		prec;
	int		hash;
	int		count;
	int		sign;
	int		isneg;
	va_list	arg;
}	t_flag;

int		ft_printf(const char *str, ...);
t_flag	*new_flag(t_flag *flag);
int		ft_isdigit(char c);
char	*ft_strchr(const char *s, int c);
int		ft_con_le_mani_flag(const char *str, int i, t_flag *flag);
int		ft_deno(char *str, int i, t_flag *flag);
char	*ft_c(char c, t_flag flag);

#endif