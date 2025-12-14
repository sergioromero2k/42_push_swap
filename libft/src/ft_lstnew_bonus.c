/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 06:31:52 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/13 07:06:22 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = malloc(sizeof(t_list));
	if (nodo == NULL)
		return (NULL);
	nodo->content = content;
	nodo->next = NULL;
	return (nodo);
}
/* int	main(void)
{
	t_list *prueba_nodo;
	int *num;

	num = malloc(sizeof(int));
	if (num == NULL)
		return (EXIT_FAILURE);

	*num=10;
	prueba_nodo = ft_lstnew(num);

	if (prueba_nodo != NULL)
	{
		printf("Valor del nodo %d\n", *(int *)prueba_nodo->content);
	}
	free(prueba_nodo);
	return (EXIT_SUCCESS);
} */