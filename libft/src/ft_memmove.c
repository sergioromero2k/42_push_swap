/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:58:35 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/09 19:33:59 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copy memory area

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ft_dest;
	const unsigned char	*ft_src;
	size_t				i;

	ft_dest = (unsigned char *)dest;
	ft_src = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		i = n;
		while (i--)
			ft_dest[i] = ft_src[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ft_dest[i] = ft_src[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void) {
	char str[] = "ABCDEFG";
	char ft_str[] = "ABCDEFG";

	memmove(str + 2, str, 5);       // Copiamos "ABCDE" empezando en str+2
	printf("%s\n", str);            // Output: "ABABCDE"

	ft_memmove(ft_str + 2, ft_str, 5);  // Copiamos "ABCDE" empezando en str+2
	printf("%s\n", ft_str);             // Output: "ABABCDE"
	return (0);
} */

/*

	* Copia un número especifico de bytes de una ubicación
	de origen a otra de destino,
	incluso si las regiones de memoria de origen y destino
	se superponen.

 * A diferencia de memcpy,
	que puede tener un comportamiento indefinido si hay superposición,
	memmove maneja de forma segura estos casos copiando
	los datos a una ubicación temporal antes de colocarlos en el destino.

	* Esto asegura que la copia sea correcta incluso cuando
	los bloques de memoria se solapan.
 * Si la direccion de memoria de dest es mayor a src, osea dest = arr
	+ 4 y src arr.
 */
