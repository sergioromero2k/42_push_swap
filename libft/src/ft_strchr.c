/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:52:58 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/29 20:59:30 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *  locate character in string
 * Retorna un puntero a la primera ocurrencia del 'c'.
 * En la cadena 's', o NULL si el carácter no se encuentra.
 * El tipo de retorno debe ser 'const char *' para no perder.
 * El calificador de const del argumento de entrada.
 */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/* int main(void){

	char s[]="Hola mundo";
	char search='a';

	char *ft_ptr=(ft_strchr(s,search));
	char *ptr=(ft_strchr(s,search));

	printf("%p\n",ft_ptr);
	printf("%p",ptr);

} */