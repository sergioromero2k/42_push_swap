/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:24:18 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/14 03:47:29 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	initializate_stack_a(int argc, char **argv)
{
	t_stack_node	*a;
	int				i;
	long			num;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!check_arg_format(argv[i], &num))
		{
			free_stack(a);
			handle_error();
		}
		add_node_to_stack(&a, (int)num);
		i++;
	}
	if (!check_duplicates(a))
	{
		free_stack(a);
		handle_error();
	}
}

int	check_arg_formater(char *str, long *num)
{
	int	i;

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		handle_error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			handle_error();
		i++;
	}
	*num = ft_atol(str);
	if (*num > INT_MAX && *num < INT_MIN)
		handle_error();
	return (EXIT_SUCCESS);
}

void	handle_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (EXIT_FAILURE);
}
int	check_duplicates(t_stack_node *a)
{
	t_stack_node	*current;
	t_stack_node	*check;

	current = a;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->next == check->next)
				handle_error();
			check = check->next;
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}
