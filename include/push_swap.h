/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:21:08 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/23 23:18:12 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int						check_arg_format(char *str, long *num);
int						check_duplicates(t_stack_node *a);
void					free_split(char **args);
void					free_stack(t_stack_node **stack);
void					handle_error_all(t_stack_node **a, char **args,
							int is_split);
void					handle_error(t_stack_node **a);
int						add_node_to_stack(t_stack_node **stack,
							t_stack_node *new);
t_stack_node			*create_node(int num);
t_stack_node			*fill_stack_a(char **args, int is_split,
							t_stack_node *a);
t_stack_node			*initializate_stack_a(int argc, char **argv);
int						can_rotate(t_stack_node *stack);
t_stack_node			*get_last_node(t_stack_node *stack);
void					rotate(t_stack_node **stack);
void					reverse_rotate(t_stack_node **stack);
void					swap(t_stack_node **stack);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
#endif