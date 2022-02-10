/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:35 by anovelli          #+#    #+#             */
/*   Updated: 2022/02/10 14:52:13 by anovelli         ###   ########.fr       */
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

# define VALID_KEYS "cspdiuxX%"
# define BASE_LOWER "0123456789abcdef"
# define BASE_UPPER "0123456789ABCDEF"

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
//utils
char	*nextarg(char *s);
int		printorigin(char *s, size_t size, t_flag flag);
//utils1
char	*ft_strchr(const char *s, int ch);
void	ft_putchar(char c, t_flag *flag);

#endif