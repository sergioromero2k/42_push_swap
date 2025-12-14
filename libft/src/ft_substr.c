/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:37:42 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/09 19:30:45 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_calloc(1, 1));
	if (len > len_s - start)
		len = len_s - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int main(void){
	const char s[]="Hola mundo";
	char  *new_s=ft_substr(s,5,3);

	printf("%s",new_s);

	if (!new_s)
		return (1);

	free(new_s);    // Para que no haya fuga de memoria
	return (0);
} */
/*
* En C puro no existe una función estándar
llamada `substr` como tal (esa es común en C++,Java, PHP, etc.).
* Pero a menudo uno mismo implementa un función con
ese nombre para obtener una subcadena de una cadena más grande.
! ¿Cúal es la idea? Dada una cadena, una posición incial y una longitud,
devuelve una nueva cadena que contiene solo esa parte.
! Como esta cadena no existe en C debes hacerlo tu, con tus condiciones.
*/