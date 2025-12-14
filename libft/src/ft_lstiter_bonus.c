/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:08:18 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/14 17:43:01 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* void	add(void *ptr)
{
	char	*str;

	str = (char *)ptr;
	ft_strcat(str, " Add");
}

int	main(void)
{
	t_list *nodo = malloc(sizeof(t_list));
	if (!nodo)
		return (1);

	// Usamos una cadena dinámica modificable
	char *str = malloc(50);
	if (!str)
		return (1);

	ft_strcpy(str, "Hola mundo");
	nodo->content = str;
	nodo->next = NULL;

	ft_lstiter(nodo, add);

	printf("%s\n", (char *)nodo->content);

	free(str);
	free(nodo);
	return (0);
} */