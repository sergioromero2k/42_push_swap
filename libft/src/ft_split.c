/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:31:26 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/18 20:08:25 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, int c)
{
	size_t	i;
	size_t	count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count_words++;
		i++;
	}
	return (count_words);
}
// aidadia,da,,,,ad,adaddd,dadd,,,,,,,,

// aidadia,da,,,,ad,adaddd,dadd,,,,,,,,

static int	ft_count_one_word(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**arr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	arr = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = ft_substr(s, i, ft_count_one_word(&s[i], c));
			if (!arr[j])
				return (ft_free(arr, j));
			j++;
			i += ft_count_one_word(&s[i], c);
		}
		else
			i++;
	}
	return (arr);
}

/* int	main(void)
{
	char	arr[] = "ola tudo bem ?";
	char	**arr_new;

	arr_new = ft_split(arr, ' ');
	printf("%s", arr_new[0]);
	printf("%s", arr_new[1]);
	printf("%s", arr_new[2]);
	printf("%s", arr_new[3]);
} */

/*
En C nativo, no existe una función split() integrada
como en otros lenguajes; sin embargo, se puede lograr un efecto
similiar utilizando la funcion `strtok()` o escribiendo tu propia
función.

Divide una cadena en subcadenas(tokens) usando un delimitador
especificado, devolviendo cada subcadena encontrada hasta que se agota
la cadena original.
*/