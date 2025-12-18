/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:24:18 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/18 12:14:20 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	check_arg_formater(char *str, long *num)
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
	t_stack_node	*check;

	while (a)
	{
		current = a;
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (EXIT_FAILURE);
			check = check->next;
		}
		a = a->next;
	}
	return (EXIT_SUCCESS);
}

