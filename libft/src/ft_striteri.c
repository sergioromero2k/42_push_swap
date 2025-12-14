/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:01:06 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/03 22:02:36 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &(s[i]));
		i++;
	}
	return ;
}
/* void	prueba(unsigned int i, char *c)
{
	if (i % 2 != 0 || i % 2 == 0)
	{
		if (*c >= 'a' && *c <= 'z')
		{
			*c = *c - 32;
		}
	}
}

int	main(void)
{
	char arr[] = "hola mundo";
	ft_striteri(arr, &prueba);
	printf("Resultado:  %s\n", arr);
	return (0);
} */