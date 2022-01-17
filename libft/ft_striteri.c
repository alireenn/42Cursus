/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:24:27 by anovelli          #+#    #+#             */
/*   Updated: 2022/01/15 16:02:26 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || (!s && !f))
		return ;
	else if (!f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
