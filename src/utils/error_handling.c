/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:18:39 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/18 11:54:15 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_stack_node **a)
{
	if (a && *a)
		free_stack(a);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
