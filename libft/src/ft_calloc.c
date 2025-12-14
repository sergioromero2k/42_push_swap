/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:21:50 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/09 19:33:48 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > (SIZE_MAX / nmemb))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
/*
* Es similar a malloc,
es una función de C que asigna memoria dinamica en el "heap".
* Su principal característica es que reserva un bloque de memoria
para un número específico de elementos,
cada uno con un tamaño de bytes determinado,
y además inicializa todos esos bytes a cero.

* Devuelve un puntero al primer elemento del bloque de memoria asignado,
o un puntero null (null) si la asginación falla.
*/