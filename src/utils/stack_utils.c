/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:18:58 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/19 12:48:26 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node_to_stack(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*last;

	if (!stack || !new)
		return (EXIT_FAILURE);
	if (!*stack)
	{
		*stack = new;
		new->prev = new;
		new->next = new;
	}
	else
	{
		last = (*stack)->prev;
		new->next = *stack;
		new->prev = last;
		last->next = new;
		(*stack)->prev = new;
	}
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

t_stack_node	*fill_stack_a(char **args, int is_split, t_stack_node *a)
{
	t_stack_node	*new_node;
	long			num;
	int				i;

	i = 0;
	while (args[i])
	{
		if (check_arg_format(args[i], &num) == EXIT_FAILURE)
			handle_error_all(&a, args, is_split);
		new_node = create_node((int)num);
		if (!new_node || add_node_to_stack(&a, new_node) == EXIT_FAILURE)
			handle_error_all(&a, args, is_split);
		i++;
	}
	if (check_duplicates(a) == EXIT_FAILURE)
		handle_error_all(&a, args, is_split);
	if (is_split)
		free_split(args);
	return (a);
}

t_stack_node	*initializate_stack_a(int argc, char **argv)
{
	t_stack_node	*a;
	char			**args;
	int				is_split;

	a = NULL;
	is_split = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		is_split = 1;
	}
	else
		args = argv + 1;
	if (!args || !args[0])
	{
		if (is_split)
			handle_error_all(&a, args, 1);
		exit(EXIT_FAILURE);
	}
	return (fill_stack_a(args, is_split, a));
}
