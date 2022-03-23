/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:45:34 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/12 20:12:47 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	received(int sig)
{
	int	rec;

	rec = 0;
	if (sig == SIGUSR1)
		++rec;
	else
	{
		ft_putstr("received");
		write(1, "\n", 1);
		exit(0);
	}	
}

void	to_bit_and_send(char *str, pid_t pid)
{
	int		i;
	int		k;

	k = 0;
	while (str[k])
	{
		i = 8;
		while (i--)
		{
			if ((str[k] >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		k++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		write(1, "\33[91mError: Not enough arguments.\033[0m\n",
			ft_strlen("\33[91mError: Not enough arguments.\033[0m\n"));
		return (0);
	}
	pid = ft_atoi(argv[1]);
	to_bit_and_send(argv[2], pid);
	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	received(SIGUSR2);
}
