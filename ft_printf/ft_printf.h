/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:00:04 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/02 14:06:17 by anovelli         ###   ########.fr       */
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
	int		count;
	va_list	arg;
}	t_flag;

int		ft_printf(const char *str, ...);
t_flag	*new_flag(t_flag *flag);
int		ft_isdigit(char c);
void	ft_putstr(char *s, t_flag *flag);
int		ft_strlen(char *s);
void	ft_putchar(char x, t_flag *flag);
char	*ft_strchr(const char *s, int c);
int		ft_check_flag(const char *str, int i, t_flag *flag);
int		ft_deno(char *str, int i, t_flag *flag);
void	ft_c(int c, t_flag *flag);
void	ft_s(char *str, t_flag *flag);
void	ft_di(int n, t_flag *flag);
void	ft_x(unsigned int x, t_flag *flag, char *base);
void	ft_u(unsigned long long x, t_flag *flag);
void	ft_p(unsigned long long x, t_flag *flag);

#endif