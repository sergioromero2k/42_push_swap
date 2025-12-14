/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serromer <serromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:40:40 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/04 12:22:02 by serromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len_total;
	char	*result;

	start = 0;
	end = ft_strlen(s);
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	while (end > start && ft_strchr(set, s[end - 1]))
		end--;
	len_total = end - start;
	result = (char *)ft_calloc(sizeof(char), (len_total + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len_total + 1);
	return (result);
}
/* int	main(void)
{
	char	*s;
	char	*set;
	char	*result;

	s = "   *zzzzz*Hola mundozzzz**   ";
	set = " *z";
	result = ft_strtrim(s, set);
	if (result)
	{
		printf("'%s'\n", result); // 'Hola mundo'
		free(result);
	}
} */

/*
* Recorre *s1 desde el incio al desde el final,
buscando caracteres que pertenezcan a set.
* Elimina todos esos caracreres del principio y del final de s1.
* Devuelve una nueva cadena que es como s1 pero
sin los caracteres del set al principio ni al final.
* Solo elimina al inicio y al final,
los caracteres dentro de la cadena que no esten al borde se quedan intactos.
 */
