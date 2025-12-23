/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:45:46 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/23 23:14:43 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!can_rotate(*stack))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		(second->next)->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}
