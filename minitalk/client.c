/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:45:34 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/09 21:43:34 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "signal.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (res);
}
int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
}

int	to_bit_and_send(char *str, pid_t pid)
{
	int		i;

	i = 8;
	while (*str)
	{
		while (i > 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1); //kill manda il segnale al pid passatogli come parametro
			else
				kill(pid, SIGUSR2);
			i--;
		}
		str++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	pid_t	*bit;

	if (argc != 3)
	{
		write(1, "\33[91mError: Not enough arguments.\033[0m\n",
			ft_strlen("\33[91mError: Not enough arguments.\033[0m\n")); //quegli strani numeri sono per dare il colore alla scritta

		return (0);
	}
	pid = ft_atoi(argv[1]);
	bit = to_bit_and_send(argv[2], pid);
}
