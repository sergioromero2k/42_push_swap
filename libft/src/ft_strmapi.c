/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:45:20 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/04 09:21:16 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	result = (char *)ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}

/* char prueba(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
	{
		if (i % 2 == 0 || i % 2 != 0)
			return (c - 32);
	}
	return (c);
}
int	main(void)
{
	char const	arr[]= "hola mundo";
	char		*result = ft_strmapi(arr, &(prueba));;

	printf("%s", result);
	return (0);
} */
