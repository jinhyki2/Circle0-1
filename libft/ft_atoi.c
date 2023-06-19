/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:05:24 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/28 09:52:40 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_check_sign(const char *str, size_t *index, int sign)
{
	while (str[*index] == '\t' || str[*index] == '\n' || str[*index] == '\v'
		|| str[*index] == '\f' || str[*index] == '\r' || str[*index] == ' ')
		(*index)++;
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			sign = -sign;
		(*index)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	size_t				index;
	int					sign;
	unsigned long long	integer;

	index = 0;
	sign = 1;
	integer = 0;
	sign = ft_check_sign(str, &index, sign);
	while (str[index] >= '0' && str[index] <= '9')
	{
		integer = integer * 10 + (str[index] - '0');
		if (integer > 9223372036854775807)
		{
			if (sign == -1)
				return (0);
			if (sign == 1)
				return (-1);
		}
		index++;
	}
	return ((int)(sign * integer));
}
