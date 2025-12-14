/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:21:29 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 20:59:36 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Convierte un caracter minusculas a su equivalente mauscula,
// y si el caracter ya es mayuscula o no es una letra,
// devuelve el carácter sin cambios.

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

/* int main(void){
	char letter='a';

	printf("%c",toupper(letter));
} */