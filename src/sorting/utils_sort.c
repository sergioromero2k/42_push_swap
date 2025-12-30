/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 04:16:39 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/30 05:17:11 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = ((*a)->next)->value;
	third = (((*a)->next)->next)->value;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
	{
		sa(a);
		ra(a);
	}
	else if (second < first && first < third)
		sa(a);
	else if (second < third && third < first)
		ra(a);
	else if (third < first && first < second)
		rra(a);
	else if (third < second && second < first)
	{
		ra(a);
		sa(a);
	}
}
void	sort_5(t_stack_node **a, t_stack_node **b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_3(a);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	push_min_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;
	int				min;
	int				pos;
	int				i;

	tmp = *a;
	min = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	move_b(a, b, i, pos);
}

void	move_b(t_stack_node **a, t_stack_node **b, int i, int pos)
{
	if (pos <= i / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = i - pos;
		while (pos-- > 0)
			rra(a);
	}
	pb(a, b);
}
