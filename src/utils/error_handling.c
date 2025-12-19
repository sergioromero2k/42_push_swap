/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:18:39 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/19 12:43:26 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*temp;
	int				size;

	if (!stack || !*stack)
		return ;
	current = *stack;
	current->prev->next = NULL;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
void	handle_error_all(t_stack_node **a, char **args, int is_split)
{
	if (a && *a)
		free_stack(a);
	if (is_split && args)
		free_split(args);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	handle_error(t_stack_node **a)
{
	if (a && *a)
		free_stack(a);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
