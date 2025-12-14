/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:31:49 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 20:57:00 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for a digit (0 through 9).

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (42);
	return (0);
}

/* int main(void){

} */