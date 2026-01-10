/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 04:16:39 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/10 21:50:26 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	pivot;

	if (ini < final)
	{
		pivot = find_pivot_index(arr, ini, final);
		quicksort(arr, ini, pivot - 1);
		quicksort(arr, pivot + 1, final);
	}
}

void	fill_index(t_stack_node *stack, int *arr, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == arr[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	assign_index(t_stack_node *stack, int stack_size)
{
	int *arr;
	int i;
	t_stack_node *tmp;

	if (!stack)
		return ;
	arr = malloc(sizeof(int) * stack_size);
	if (!arr)
		return ;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	quicksort(arr, 0, stack_size - 1);
	fill_index(stack, arr, stack_size);
	free(arr);
}
