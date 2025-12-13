/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:24:18 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/13 03:21:32 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	initializate_stack_a(int argc, char **argv)
{
	t_stack_node	*a;
    int i;

    i=1;
    while(i<argc){
        
        
    }
	
}

void	handle_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (EXIT_FAILURE);
}
void check_duplicates(int count, char **arr){
    int i;
    int j;

    i=0;
    while(i<count){
        j=i+1;
        while(j<count){
            if(*arr[i]=*arr[j])
                handle_error();
            j++;
        }
        i++;
    }
}