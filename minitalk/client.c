/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:45:34 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/11 19:14:27 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

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
	while (str[i] != '\0')
		i++;
	return (i);
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
	printf("%d \n", pid);
	to_bit_and_send(argv[2], pid);
}
