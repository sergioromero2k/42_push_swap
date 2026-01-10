/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:21:08 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/10 23:16:54 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/* --- Estructuras --- */

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef struct s_cost
{
	int					cost_a;
	int					cost_b;
	int					total_cost;
	int					target_index;
	t_stack_node		*node_b;
}						t_cost;

/* --- Parsing y Errores (src/utils/) --- */

int						check_arg_format(char *str, long *num);
int						check_duplicates(t_stack_node *a);
void					free_split(char **args);
void					free_stack(t_stack_node **stack);
void					handle_error(t_stack_node **a);
void					handle_error_all(t_stack_node **a, char **args,
							int is_split);

/* --- Gestión de Stack (src/utils/ y src/operations/) --- */

t_stack_node			*create_node(int num);
int						add_node_to_stack(t_stack_node **stack,
							t_stack_node *new);
/* Añadido fill_stack_a que faltaba en el header */
t_stack_node			*fill_stack_a(char **args, int is_split,
							t_stack_node *a);
t_stack_node			*initializate_stack_a(int argc, char **argv);
int						get_stack_size(t_stack_node *stack);
t_stack_node			*get_last_node(t_stack_node *stack);

/* --- Operaciones Maestras (src/operations/) --- */

void					rotate(t_stack_node **stack);
void					reverse_rotate(t_stack_node **stack);
void					swap(t_stack_node **stack);
void					push(t_stack_node **dest, t_stack_node **src);

/* --- Reglas Oficiales (src/rules/) --- */

/* --- Reglas (Rules) --- */
void					sa(t_stack_node **a, int print);
void					sb(t_stack_node **b, int print);
void					ss(t_stack_node **a, t_stack_node **b, int print);
void					pa(t_stack_node **a, t_stack_node **b, int print);
void					pb(t_stack_node **a, t_stack_node **b, int print);
void					ra(t_stack_node **a, int print);
void					rb(t_stack_node **b, int print);
void					rr(t_stack_node **a, t_stack_node **b, int print);
void					rra(t_stack_node **a, int print);
void					rrb(t_stack_node **b, int print);
void					rrr(t_stack_node **a, t_stack_node **b, int print);

/* --- Algoritmos de Ordenación (src/sorting/) --- */

void					sort_3(t_stack_node **a);
void					turk_sort(t_stack_node **a, t_stack_node **b);
void					assign_index(t_stack_node *stack, int stack_size);
void					quicksort(int arr[], int ini, int final);
/* Añadido ft_swap si lo usas fuera de quicksort */
void					ft_swap(int *a, int *b);

/* --- Utilidades de Turk Engine (src/sorting/) --- */

int                     get_node_pos(t_stack_node *stack, int index);
int                     find_target(t_stack_node *a, int b_index);
int                     find_min_index(t_stack_node *stack);
t_cost                  calc_node_cost(t_stack_node *a, t_stack_node *b,
                            int b_idx);
t_cost                  get_best_move(t_stack_node *a, t_stack_node *b);
void                    execute_moves(t_stack_node **a, t_stack_node **b,
                            t_cost c);

/* --- NUEVAS ADICIONES PARA EL BONUS --- */
int                     is_sorted(t_stack_node *stack);
char                    *get_next_line(int fd);

#endif