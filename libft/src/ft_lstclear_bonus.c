/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:33:32 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/14 17:34:56 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*backup;

	head = *lst;
	if (!head || !del)
		return ;
	while (head)
	{
		backup = head->next;
		del(head->content);
		free(head);
		head = backup;
	}
	*lst = NULL;
}

/* void del_str(void *ptr){
	free(ptr);
}
int	main(void){
	t_list *list=NULL;
	t_list *nodo=malloc(sizeof(t_list));
	char *str;

	str=ft_strdup("Hola mundo");
	nodo->content=str;
	nodo->next=NULL;

} */