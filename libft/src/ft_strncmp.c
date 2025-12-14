/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:08:15 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 20:58:28 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *  Compare two strings.
 *  The strncmp() function is similar,
	except it compares only the first (at most) n bytes of s1 and s2.
 *  0, if the s1 and s2 are equal;
 *  a negative value if s1 is less than s2;
 *  a positive value if s1 is greater than s2.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/* int main(void){
	const char buffer[7]="JoelAll";
	const char buffer2[4]="Joel";

	int result=ft_strncmp(buffer,buffer2,5);

	printf("%d",result);
} */