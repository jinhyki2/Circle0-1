/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoah.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:46:18 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/05/01 11:07:57 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_length(unsigned int u_integer)
{
	size_t	len;

	len = 0;
	if (u_integer == 0)
		len = 1;
	while (u_integer > 0)
	{
		len++;
		u_integer = u_integer / 16;
	}
	return (len);
}

char	*ft_itoah(unsigned int n, char c)
{
	unsigned int	u_integer;
	size_t			len;
	char			*ret;

	u_integer = n;
	len = ft_length(u_integer);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ret))
		return (0);
	ret[len] = '\0';
	if (u_integer == 0)
		ret[0] = '0';
	while (u_integer > 0)
	{
		if (c == 'x')
			ret[--len] = "0123456789abcdef"[u_integer % 16];
		else
			ret[--len] = "0123456789ABCDEF"[u_integer % 16];
		u_integer = u_integer / 16;
	}
	return (ret);
}
