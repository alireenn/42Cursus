/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:35 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/16 18:13:34 by anovelli         ###   ########.fr       */
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

# define KEYS "cspdiuxX%"
# define LOWER "0123456789abcdef"
# define UPPER "0123456789ABCDEF"

typedef struct s_flag
{
	char	type;
	int		counter;
	int		minus;
	int		zero;
	int		point;
	int		accuracy;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		uppercase;
}	t_flag;

int		ft_printf(const char *str, ...);
t_flag	*new_flag(void);
void	reset_flag(t_flag *flag);
//utils 		COMPLETO
char	*nextarg(char *s);
int		printorigin(char *s, size_t size, t_flag *flag);
void	parseflag(char *s, t_flag *flag);
char	*get_flag(char *s, t_flag *flag);
char	*parsearg(char *s, va_list args, t_flag *flag);
//utils1		COMPLETO
char	*ft_strchr(const char *s, int ch);
void	ft_putchar(char c, t_flag *flag);
int		ft_atoi(const char *s);
int		get_digit(long long n);
void	prepare_int(int num, int tp, t_flag *flag);
//utils2		COMPLETO
void	print_zero(int n, t_flag *flag);
int		ft_putnbr(long long n, t_flag *flag);
int		ft_isdigit(int n);
void	prehex(char *s, long long n, int tp, t_flag *flag);
int		putnbr_hex(char c, long long n, t_flag *flag);
//ft_deno 			COMPLETO
char	*ft_c(char *a, va_list args, t_flag *flag);
char	*ft_s(char *s, char *arg, t_flag *flag);
char	*ft_di(char *s, int num, t_flag *flag);
char	*ft_u(char *s, va_list args, t_flag *flag);
char	*ft_p(char *s, va_list args, t_flag *flag);
//ft_deno2
char	*ft_hex(char *s, va_list args, t_flag *flag);
//utils_string 			COMPLETO
void	print_space(int n, t_flag *flag);
int		ft_strlen(char	*s);
void	ft_putstr(char *str, t_flag *flag);
int		get_hex(unsigned long n);
void	putnbr_p(unsigned long n, t_flag *flag);

#endif