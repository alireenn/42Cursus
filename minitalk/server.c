/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:46:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/09 21:36:10 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_putchar(char x, int fd)
{
	write (fd, &x, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', fd);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0', fd);
		return ;
	}
	else
		ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}

void	powpow(pid_t pid)
{
	
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	powpow(pid);
}
