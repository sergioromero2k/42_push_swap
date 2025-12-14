/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:30:07 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/15 06:23:43 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* int	main(void)
{
	t_list *node;
	t_list *node1;
	t_list *node2;
	t_list *node3;
	int *num1;
	int *num2;
	int *num3;

	node = NULL;
	num1 = malloc(sizeof(int));
	num2 = malloc(sizeof(int));
	num3 = malloc(sizeof(int));
	*num1 = 10;
	*num2 = 12;
	*num3 = 15;
	node1 = malloc(sizeof(t_list));
	if (!node1)
		return (1);
	node1->content = num1;
	node2 = malloc(sizeof(t_list));
	if (!node2)
		return (1);
	node2->content = num2;
	node3 = malloc(sizeof(t_list));
	if (!node3)
		return (1);
	node3->content = num3;

	ft_lstadd_front(&node, node1);
	ft_lstadd_front(&node, node2);
	ft_lstadd_front(&node, node3);

	printf("%p\n", num1);
	printf("%p\n", ft_lstlast(node)->content);

	free(node1);
	free(node2);
	free(node3);
	free(num1);
	free(num2);
	free(num3);
	return (0);
} */