/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:46:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/11 18:34:55 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static void	ft_putchar(char x, int fd)
{
	write (fd, &x, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 10)
	{
		ft_putchar(n + '0', fd);
		return ;
	}
	else
		ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}

void	ft_handler(int sig)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

void	powpow(pid_t pid)
{
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	powpow(pid);
	signal(SIGUSR2, ft_handler);
	signal(SIGUSR1, ft_handler);
	while (1)
		pause();
	return (0);
}