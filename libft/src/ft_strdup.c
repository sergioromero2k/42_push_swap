/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:43:46 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/09 19:34:32 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy_s;
	int		len_s;
	size_t	i;

	i = 0;
	len_s = ft_strlen(s);
	copy_s = ft_calloc(len_s + 1, (sizeof(char)));
	if (!copy_s)
		return (NULL);
	while (s[i])
	{
		copy_s[i] = s[i];
		i++;
	}
	return (copy_s);
}

/* int main(void){
	const char *original="Hola mundo";
	char *copia = ft_strdup(original);

	if (copia == NULL){
		perror("Error al duplicar cadena");
		return (1);
	}

	printf("Original: %s\n", original);
	printf("Copia: %s\n", copia);
	printf("Copia: %s\n", copia);


	free(copia);                // Para que no haya fuga de memoria.
	return (0);
} */

/*
Es una función que toma una cadena como entrada,
reserva memoria suficiente para crear
una copia de ella y luego en esa nueva memoria,
devolviendo un puntero a la cadena recién creada,
que es idéntica a la original.
*/
