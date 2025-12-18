/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:21:08 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/18 12:00:29 by sergio-alej      ###   ########.fr       */
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

t_stack_node			*initializate_stack_a(int argc, char **argv);
int						check_arg_formater(char *str, long *num);
void					handle_error(t_stack_node **a);
int						check_duplicates(t_stack_node *a);
void					free_stack(t_stack_node **stack);
t_stack_node			*create_node(int num);
int						add_node_to_stack(t_stack_node **stack,
							t_stack_node *new);

#endif