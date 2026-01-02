/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 04:16:39 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/02 05:37:26 by sergio-alej      ###   ########.fr       */
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

void	assign_index(t_stack_node *a, int *sorted_arr, int size)
{
}

t_stack_node	*find_max(t_stack_node *stack)
{
}

t_stack_node	*find_min(t_stack_node *stack)
{
}
