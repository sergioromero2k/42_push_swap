/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 05:20:43 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/30 05:21:03 by sergio-alej      ###   ########.fr       */
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
