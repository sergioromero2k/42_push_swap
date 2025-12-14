/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:44:58 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/14 16:50:48 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/* void	del_string(void *ptr)
{
	free(ptr);
}

int	main(void)
{
	t_list *node = malloc(sizeof(t_list));
	node->content = ft_strdup("42 Madrid");
	node->next = NULL;
} */