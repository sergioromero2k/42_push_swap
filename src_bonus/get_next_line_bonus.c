/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serromer <serromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:14:07 by sergio-alej       #+#    #+#             */
/*   Updated: 2026/01/15 07:43:23 by serromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strjoin_mini(char *s1, char c)
{
	char	*res;
	int		i;

	i = 0;
	while (s1 && s1[i])
		i++;
	res = malloc(i + 2);
	if (!res)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	free(s1);
	return (res);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int		rd;

	if (fd < 0)
		return (NULL);
	line = NULL;
	rd = read(fd, &buffer, 1);
	while ((rd) > 0)
	{
		line = ft_strjoin_mini(line, buffer);
		if (buffer == '\n')
			break ;
		rd = read(fd, &buffer, 1);
	}
	if (rd <= 0 && !line)
		return (NULL);
	return (line);
}
