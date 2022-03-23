/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:52:57 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/12 20:12:54 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h> 

int		ft_atoi(const char *str);
void	ft_putstr(char *str);
int		ft_strlen(char	*str);
void	ft_putchar(char x, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif