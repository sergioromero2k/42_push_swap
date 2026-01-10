/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:24:18 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/10 22:24:43 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg_format(char *str, long *num)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (EXIT_FAILURE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	*num = ft_atol(str);
	if (*num > INT_MAX || *num < INT_MIN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_duplicates(t_stack_node *a)
{
	t_stack_node	*current;

	while (a)
	{
		current = a->next;
		while (current)
		{
			if (a->value == current->value)
				return (EXIT_FAILURE);
			current = current->next;
		}
		a = a->next;
	}
	return (EXIT_SUCCESS);
}
