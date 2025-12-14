/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:51:18 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 21:00:38 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Verifica si un carácter es una letra (a-z o A-Z).

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (42);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>

int	main(void){
	char caracter1;

	caracter1='@';

	printf("%d",ft_isalpha(caracter1));

} */