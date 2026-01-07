/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 05:23:43 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/07 13:06:09 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack_node *stack)
{
	int				min_index;
	t_stack_node	*tmp;

	tmp = stack;
	min_index = stack->index;
	while (tmp)
	{
		if (min_index > (tmp->index))
			min_index = tmp->index;
		tmp = tmp->next;
	}
	return (min_index);
}
int	find_target(t_stack_node *a, int b_index)
{
	t_stack_node *tmp;
	int target_index;
	int min_diff;
	int diff;

	tmp = a;
	target_index = -1;
	min_diff = INT_MAX;

	while (tmp)
	{
		diff = tmp->index - b_index;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (target_index == -1)
		target_index = find_min_index(a);

	return (target_index);
}
