/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:46:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/12 20:13:33 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static pid_t			client_pid = 0;

	if (!client_pid)
		client_pid = info->si_pid;
	context = (ucontext_t *)context;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
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
	struct sigaction	act;
	pid_t				pid;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &ft_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	pid = getpid();
	powpow(pid);
	while (1)
		pause();
	return (0);
}
