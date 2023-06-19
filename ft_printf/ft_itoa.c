/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:23:19 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/05/01 11:07:26 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_length(long long integer)
{
	size_t	len;

	len = 0;
	if (integer == 0)
		len = 1;
	else if (integer < 0)
	{
		integer = -integer;
		len++;
	}
	while (integer > 0)
	{
		len++;
		integer = integer / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	integer;
	size_t		len;
	char		*ret;

	integer = n;
	len = ft_length(integer);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ret))
		return (0);
	ret[len] = '\0';
	if (integer == 0)
		ret[0] = '0';
	if (integer < 0)
	{
		ret[0] = '-';
		integer = -integer;
	}
	while ((--len >= 0) && (integer != 0))
	{
		ret[len] = integer % 10 + '0';
		integer = integer / 10;
	}
	return (ret);
}

char	*ft_uitoa(unsigned int u_integer)
{
	size_t		len;
	char		*ret;

	len = ft_length(u_integer);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ret))
		return (0);
	ret[len] = '\0';
	if (u_integer == 0)
		ret[0] = '0';
	while ((--len >= 0) && (u_integer != 0))
	{
		ret[len] = u_integer % 10 + '0';
		u_integer = u_integer / 10;
	}
	return (ret);
}
