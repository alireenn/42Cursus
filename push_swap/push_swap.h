/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:58 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/17 16:21:10 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	int		args;
	bool	is_correct;
	int		str_nbrs;
	int		*lis;
	int		lis_num_max;
}				t_stack;

// typedef struct s_node{
// 	int				n;
// 	struct s_node	*next;
// }	t_node;

// typedef struct s_stacks{
// 	t_node	*a;
// 	t_node	*b;
// 	int		isok;
// }	t_stacks;
					/*	check	*/
//check.c

#endif