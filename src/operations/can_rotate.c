/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:01:19 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/23 22:02:55 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	can_rotate(t_stack_node *stack)
{
	if (!stack)
		return (0);
	if (!stack->next)
		return (0);
	return (1);
}
