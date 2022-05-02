/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:58 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/02 17:54:46 by anovelli         ###   ########.fr       */
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
void	create_a(void);
void	create_b(void);
void	finish(t_stacks *point);

			/*checks*/
//check.c
bool	check(char **ac);
bool	is_string(char	**ac);
bool	is_ok(char	ac);
bool	is_number(char	ac);

#endif