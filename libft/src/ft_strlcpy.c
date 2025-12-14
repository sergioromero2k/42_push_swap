/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:58:29 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/08 20:42:59 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strlcpy : "String Length Copy"
// strlcpy : "Copiar Longitud de Cadena"
// Devuelve la cantidad de total de la cadena
// Si no hay size, retorna size if (size <= 0)
// size-1, porque el ultimo vale \0 while ((i < size - 1) && (src[i]))

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (size <= 0)
		return (len_src);
	while ((i < size - 1) && (src[i]))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

/* int main(void)
{
	char arr1[] = "Hola pepe";
	char arr2[2];

	char ft_arr1[] = "Hola pepe";
	char ft_arr2[2];

	strlcpy(arr2, arr1, sizeof(arr2));
	printf("%ld", strlcpy(arr2, arr1, sizeof(arr2)));
	printf("\n%s", arr2);

	printf("\n");

	ft_strlcpy(ft_arr2,ft_arr1,sizeof(ft_arr2));
	printf("%ld", ft_strlcpy(ft_arr2, ft_arr1, sizeof(ft_arr2)));
	printf("\n%s", ft_arr2);

} */
/*
* Es una función de C que copia una cadena
origen (src) a un búfer destino (dst),
copiando hasta size-1 y garantizando que el
resultado este siempre terminado con un carácter nulo (\0).

* Esto es para evitar dsbordamientos y devolver la longitud
total de la cadena que debería haberse copiado si hubiera espacio ilimitado.
* size = tamaño total del buffer dst.
* Debes tener en cuenta que siempre copia hasta \0 al final.
 */
