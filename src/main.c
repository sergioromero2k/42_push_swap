/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:19:35 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/10 23:20:36 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 2)
		sa(a,1);
	else if (size == 3)
		sort_3(a);
	else
		turk_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	a = NULL;
	b = NULL;
	a = initializate_stack_a(argc, argv);
	if (!a)
		return (0);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	assign_index(a, get_stack_size(a));
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
