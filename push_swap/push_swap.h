/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:58 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/09 11:20:15 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef	struct s_node{
	int					n;
	struct s_node	*head;
	struct s_node	*next;
}	t_node;

typedef struct s_stacks{
	t_node	*a;
	t_node	*b;
}	t_stacks;

			/*rules*/
//rules.c
void	sa(t_stacks *stacks);

//fill_stacks.c
char	**ft_split(const char *s, char c);
size_t	get_word(const char *s, char c);
void	fill_stack(int av, char **ac);

			/*checks*/
//check.c
bool	check(char **ac);
bool	is_string(char	**ac);
bool	is_ok(char	ac);
bool	is_number(char	ac);

#endif