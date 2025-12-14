/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 01:33:58 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 21:22:15 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pt_s1;
	unsigned char	*pt_s2;

	i = 0;
	pt_s1 = (unsigned char *)s1;
	pt_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (pt_s1[i] != pt_s2[i])
			return ((int)pt_s1[i] - (int)pt_s2[i]);
		i++;
	}
	return (0);
}

/* int main()
{
	const char *ft_data = "1234";
	const char *ft_data_s = "123456";
	const char *data = "1234";
	const char *data_s = "123456";

	// Compara los dos primeros strings
	int ft_res = ft_memcmp(ft_data, ft_data_s, 5);
	int res = memcmp(data, data_s, 5);

	printf("ft_res: %i\n",ft_res);
	printf("res: %i",res);
} */
/*
* Compara el contenido de dos bloques de memoria (búferes)
byte a byte hasta un número especificado de bytes (count).
* Devuelve un valor que indica la relación entre ellos: 0 si son iguales.
* Un valor negativo si el primer búfer es menor que el segundo.
* Un valor positivo si es mayor.
 */
