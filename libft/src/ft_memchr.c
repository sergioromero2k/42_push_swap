/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:36:19 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 21:15:31 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&(ptr[i]));
		i++;
	}
	return (NULL);
}

/* int main(void) {
	char data[] =  {'\0', '\0', '\0', 'm'};
	char ft_data[] = {'\0', '\0', '\0', 'm'};
	char* ptr;
	char* ft_ptr;

	ptr = memchr(data, 'm', 4);
	ft_ptr = ft_memchr(ft_data, 'm', 4);

	printf("memchr: %p\n", ptr);
	printf("ft_memchr: %p\n", ft_ptr);

	return (0);
} */

/*
* The  memchr()  function scans the initial n bytes
of the memory area pointed to by s for the first instance of c.
* Both c and the bytes of the memory area pointed
to by s are interpreted as unsigned char.
 */
/*
Busca la primera aparición de un carácter específico (c)
dentro de un número determinado de bytes (count) de un área de memoria (buf),
devolviendo un puntero a esa primera aparición si se encuentram
o un puntero nulo si no se encuentra el carácter dentro del rango espcificado.
*/