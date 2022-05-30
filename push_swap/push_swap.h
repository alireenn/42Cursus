/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:58 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/30 12:54:11 by anovelli         ###   ########.fr       */
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
	// int		args;
	bool	is_correct;
	int		str_nbrs;
	int		*lis;
	int		lis_num_max;
}				t_stack;

					/*	check	*/
//check.c
bool			is_ok(char ac);
bool			is_number(char ac);
bool			is_string(char **ac);
bool			check(char **ac);
					/*order*/
//small_swap.c
void			decrescent_algorithm(t_stack *stack);
void			sort_three(t_stack *stack);
void			sort_five(t_stack *stack);
void			choose_alg(t_stack *stack);
int				find_min_pos(t_stack *stack);
//big_soreta.c
void			big_sort(t_stack *stack);
void			ft_lis2(t_stack *stack);
int				ft_lis3(t_stack *stack);
void			ft_lis(t_stack *stack);
					/*rules*/
void			array_fill(char **argv, t_stack *stack);
int				fill_helper(t_stack *stack, int k, char *str);
//rules.c
void			ft_sa(t_stack *stack, bool can_write);
void			ft_ra(t_stack *stack, bool can_write);
void			ft_rra(t_stack *stack, bool can_write);
void			ft_pa_helper(t_stack *stack, int *tmp);
void			ft_pa(t_stack *stack, bool can_write);
//rules2.c
void			ft_sb(t_stack *stack, bool can_write);
void			ft_rb(t_stack *stack, bool can_write);
void			ft_rrb(t_stack *stack, bool can_write);
void			ft_pb_helper(t_stack *stack, int *tmp);
void			ft_pb(t_stack *stack, bool can_write);
//rules3.c
void			ft_rrab(t_stack *stack, bool can_write);
void			ft_rab(t_stack *stack, bool can_write);
void			ft_sab(t_stack *stack, bool can_write);
			/*utils*/
//ft_split.c
int				ft_strlen(const char *str);
size_t			get_word(const char *s, char c);
char			**ft_split(const char *s, char c);
int				find_min(t_stack *stack);
//int_utils.c
void			free_matrix(char **matrix);
bool			is_int(long long int nb);
int				atoi_helper(char *str);
long long int	ft_atoi(const char *str);
int				count_numbers(char **argv);
//utils_string.c
int				ft_putchar(char c, int fd);
int				ft_putstr(char *s, int fd);
bool			is_in_string(char c, char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *src);
#endif