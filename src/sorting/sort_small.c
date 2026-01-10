/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 05:20:43 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/10 22:53:44 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack_node **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->value;
	s = (*a)->next->value;
	t = (*a)->next->next->value;
	if (f > s && s < t && f < t)
		sa(a, 1);
	else if (f > s && s > t)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (f > s && s < t && f > t)
		ra(a, 1);
	else if (f < s && s > t && f < t)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (f < s && s > t && f > t)
		rra(a, 1);
}
