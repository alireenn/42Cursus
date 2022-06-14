/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:46:23 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/08 16:51:00 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"

typedef struct s_stack
{
	int	*array;
	int	min;
	int	max;
	int	len;
	int	*best;
	int	best_len;
}t_stack;

typedef struct s_best_elem
{
	int					val;
	int					len;
	struct s_best_elem	*next;
}t_best_elem;

int		control_arg(int argc, char ***argv2, char **argv, int *i);
void	sa(t_stack *a, int to_print);
void	sb(t_stack *b, int to_print);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a, int to_print);
void	rb(t_stack *b, int to_print);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int to_print);
void	rrb(t_stack *b, int to_print);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	move_up(t_stack *a);
void	move_down(t_stack *a);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
void	move_b(int *ind, t_stack *b);
void	err(char *str);
int		ft_abs(int c);
void	allocate(t_stack *a, t_stack *b, int argc);
void	checks(int argc, char **argv, t_stack *a, int flag);
int		check_char(char *argv);
long	ft_atol(const char *str);
void	find_max_min(t_stack *a);
int		find_min_arr(int *arr, int len);
int		find_place(t_stack *b, int val);
void	find_place_and_insert(t_stack *a, t_stack *b, int moves);
int		ordered(t_stack *a);
void	find_min(t_stack *a);
int		find_ind(t_stack *a, int val);
void	allocate_lists(t_best_elem **n, t_best_elem **b, int len);
int		get_half(t_stack *a, int min, int max);
void	range(t_stack *a, t_stack *b, int min, int max);
int		to_do_a(t_stack *a, int min, int max);
void	fill_range(t_stack *a, t_stack *b, int min, int flag);
int		to_do(t_stack *b, int min, int max);
int		in_best(t_stack *a, int val);
void	get_lis(int *array, int len, t_stack *a);
void	choose_bet(t_stack *a, t_stack *b, int *moves, int *i);
void	choose_min(t_stack *a, t_stack *b, int *ind);
void	choose_max(t_stack *a, t_stack *b, int *ind);
void	change_ind(int flag, int *moves, int len_b);
int		decide(t_stack *a, t_stack *b);
void	checker_rrr(t_stack *a, t_stack *b);
void	checker_rra(t_stack *a);
void	checker_rrb(t_stack *a);
void	checker_rr(t_stack *a, t_stack *b);
void	checker_ra(t_stack *a);
void	checker_rb(t_stack *a);
void	checker_sa(t_stack *a);
void	checker_sb(t_stack *a);
void	checker_ss(t_stack *a, t_stack *b);
void	checker_pb(t_stack *a, t_stack *b);
void	checker_pa(t_stack *a, t_stack *b);

#endif
