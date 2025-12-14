/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serromer <serromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:24:23 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/04 12:22:29 by serromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((ptr[i] == ' ') || ((ptr[i] >= 9) && (ptr[i] <= 13)))
		i++;
	if ((ptr[i] == '+') || (ptr[i] == '-'))
	{
		if (ptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ((ptr[i] >= '0') && (ptr[i] <= '9'))
	{
		if (result > INT_MAX || result < INT_MIN)
			return (0);
		result = result * 10 + ptr[i] - '0';
		i++;
	}
	return (result * sign);
}
/* int	main(void)
{
	char	*cadena_numero;
	char	*cadena_numero2;
	int		numero_entero;
	int		numero_entero2;

	cadena_numero = "-214748364877";
	cadena_numero2 = "-2147483648";
	numero_entero = ft_atoi(cadena_numero);
	numero_entero2 = ft_atoi(cadena_numero2);
	printf("La cadena es: \"%s\"\n", cadena_numero);
	printf("El número entero es: %d\n", numero_entero);
	printf("El número entero es: %d\n", numero_entero2);

	return (0);
} */
/*
Convert a string a to an integer
* Es una función de programación que convierte una
cadena de caracteresult que contiene un número a su represultentación entera.
* Es decir, toma un texto "123" y lo transforma en el número entero 123,
que luego se puede usar en operaciones matemáticas.
* Devuelve un número entero corresultpondiente.
 */
