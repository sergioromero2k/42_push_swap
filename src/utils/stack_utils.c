/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:18:58 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/18 12:11:04 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	add_node_to_stack(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*last_node;

	if (!stack || !new)
		return (EXIT_FAILURE);
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
		new->next = NULL;
		return (EXIT_SUCCESS);
	}
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new;
	new->prev = last_node;
	new->next = NULL;
	return (EXIT_SUCCESS);
}

t_stack_node	*create_node(int num)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack_node	*initializate_stack_a(int argc, char **argv)
{
	t_stack_node	*a;
	int				i;
	long			num;
	t_stack_node	*new_node;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!check_arg_format(argv[i], &num))
			handle_error(&a);
		new_node = create_node((int)num);
		if (!new_node)
			handle_error(&a);
		if (add_node_to_stack(&a, new_node) == EXIT_FAILURE)
			handle_error(&a);
		i++;
	}
	if (check_duplicates(a) == EXIT_FAILURE)
		handle_error(&a);
	return (a);
}
