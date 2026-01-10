/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 05:23:43 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/10 22:05:27 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "push_swap.h"

int	find_min_index(t_stack_node *stack)
{
	int				min;
	t_stack_node	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	find_target(t_stack_node *a, int b_index)
{
	t_stack_node	*tmp;
	long			best_target_idx;

	tmp = a;
	best_target_idx = LONG_MAX;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < best_target_idx)
			best_target_idx = tmp->index;
		tmp = tmp->next;
	}
	if (best_target_idx == LONG_MAX)
		return (find_min_index(a));
	return ((int)best_target_idx);
}

t_cost	get_best_move(t_stack_node *a, t_stack_node *b)
{
	t_cost			best;
	t_cost			curr;
	t_stack_node	*tmp_b;

	tmp_b = b;
	best.total_cost = INT_MAX;
	while (tmp_b)
	{
		curr = calc_node_cost(a, b, tmp_b->index);
		if (curr.total_cost < best.total_cost)
			best = curr;
		tmp_b = tmp_b->next;
	}
	return (best);
}

void	final_adjustment(t_stack_node **a)
{
	int	size;
	int	pos;

	size = get_stack_size(*a);
	pos = get_node_pos(*a, 0);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

void	turk_sort(t_stack_node **a, t_stack_node **b)
{
	int size;

	size = get_stack_size(*a);
	while (size > 3)
	{
		pb(a, b);
		size--;
	}
	sort_3(a);
	while (*b)
	{
		execute_moves(a, b, get_best_move(*a, *b));
		pa(a, b);
	}
	final_adjustment(a);
}
