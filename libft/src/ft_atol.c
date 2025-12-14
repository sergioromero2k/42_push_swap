/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 03:04:15 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/14 03:19:03 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *ptr)
{
	long result = 0;
	int sign = 1;

	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + (*ptr - '0');
		ptr++;
	}
	return (sign * result);
}
