/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 01:58:32 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/09 16:19:12 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && (i + j) < len && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/* int main() {
	// const char *text = "hola mundo";
	// const char *needle = "mun";
	const char *ft_text = "hola mundo";
	const char *ft_needle = "mun";

	// char *res = strnstr(text, needle, 11); // len >= longitud de text
	char *ft_res = ft_strnstr(ft_text, ft_needle, 11);
		// len >= longitud de text

	// printf("%p",res);
	printf("%p",ft_res);

	return (0);
} */