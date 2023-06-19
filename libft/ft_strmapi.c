/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:25:30 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/25 19:27:19 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			len;
	char			c;
	char			*ret;

	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ret))
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		c = (*f)(index, s[index]);
		ret[index] = c;
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
