/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 04:16:39 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/02 04:38:06 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
int	find_pivot_index(int arr[], int ini, int final)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[final];
	i = ini - 1;
	j = ini;
	while (j < final)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[final]);
	return (i + 1);
}
void	quicksort(int arr[], int ini, int final)
{
	int pivot;

	if (ini < final)
	{
		pivot = find_pivot_index(arr, ini, final);
		quicksort(arr, ini, pivot - 1);
		quicksort(arr, pivot + 1, final);
	}
}
