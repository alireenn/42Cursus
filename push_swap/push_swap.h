/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:58 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/09 17:51:19 by anovelli         ###   ########.fr       */
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
	int		isok;
}	t_stacks;

			/*rules*/
//rules.c
void	sa(t_stacks *stacks);

//fill_stacks.c
void	fill_stack(char **ac, t_stacks *stack_a);
int		find_space(char *str, char c);
int		count_space(char *str);
int		fill_helper(char *str, int index, t_stacks *stack_a);

			/*checks*/
//check.c
bool	check(char **ac);
bool	is_string(char	**ac);
bool	is_ok(char	ac);
bool	is_number(char	ac);

			/*utils*/
//ft_split.c
char	**ft_split(const char *s, char c);
size_t	get_word(const char *s, char c);
int		ft_strlen(const char *str);

//int_utils.c
int		ft_atoi(const char *str);
int		is_int(int n);
void	*ft_lstnew(long long int content);
void	ft_lstadd(t_node **lst);

//utils_string.c
int		ft_putchar(char c, int fd);
int		ft_putstr(char *s, int fd);
bool	is_in_string(char c, char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);

#endif