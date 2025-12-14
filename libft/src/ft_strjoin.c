/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:36:14 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/11 22:34:39 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_new;
	char	*s2_new;
	char	*str;

	s1_new = (char *)s1;
	s2_new = (char *)s2;
	str = (char *)ft_calloc(ft_strlen(s2) + ft_strlen(s1) + 1, 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (ft_strlen(s1_new) + 1));
	ft_strlcat(str, s2, ft_strlen(s1_new) + ft_strlen(s2_new) + 1);
	return (str);
}

/* int main(void){
	char const s1[]="Holapepepepe ";
	char const s2[]=" Mundo";
	char *str;

	str=ft_strjoin(s1,s2);

	printf("%s",str);

	free(str); // Liberar memoria(heap) para que no haya fuga de memoria.
	return (0);
} */
/*
 * No existe una función llamada strjoin,
pero muchas bibliotecas (o implementaciones propias)
	la usan para unir 2 cadenas en una sola.
 * Toma dos (o más) cadenas como entrada.
 * Devuelve una nueva cadena que contiene todas concatenadas.
 * Generalmente reserva memoria dinámica con malloc,
	incluyendo espacio para el terminador \0.
 */
