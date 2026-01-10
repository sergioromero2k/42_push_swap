/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:14:45 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/10 22:59:04 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_pos(t_stack_node *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	get_total_cost(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		return (ft_abs(b));
	}
	return (ft_abs(a) + ft_abs(b));
}

t_cost	calc_node_cost(t_stack_node *a, t_stack_node *b, int b_index)
{
	t_cost	c;
	int		size_a;
	int		size_b;
	int		pos_a;
	int		pos_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	c.target_index = find_target(a, b_index);
	pos_a = get_node_pos(a, c.target_index);
	pos_b = get_node_pos(b, b_index);
	if (pos_b <= size_b / 2)
		c.cost_b = pos_b;
	else
		c.cost_b = pos_b - size_b;
	if (pos_a <= size_a / 2)
		c.cost_a = pos_a;
	else
		c.cost_a = pos_a - size_a;
	c.total_cost = get_total_cost(c.cost_a, c.cost_b);
	return (c);
}

void	execute_moves(t_stack_node **a, t_stack_node **b, t_cost c)
{
	while (c.cost_a > 0 && c.cost_b > 0)
	{
		rr(a, b, 1);
		c.cost_a--;
		c.cost_b--;
	}
	while (c.cost_a < 0 && c.cost_b < 0)
	{
		rrr(a, b, 1);
		c.cost_a++;
		c.cost_b++;
	}
	while (c.cost_a > 0 && c.cost_a--)
		ra(a, 1);
	while (c.cost_a < 0 && c.cost_a++)
		rra(a, 1);
	while (c.cost_b > 0 && c.cost_b--)
		rb(b, 1);
	while (c.cost_b < 0 && c.cost_b++)
		rrb(b, 1);
}
