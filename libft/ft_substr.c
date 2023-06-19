/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:26:10 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/04/26 14:24:31 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_s_to_ret(char *ret, char const *s,
		unsigned int start, size_t len)
{
	size_t	index;
	size_t	index_ret;

	index = start;
	index_ret = 0;
	while ((index_ret < len) && (s[index] != '\0'))
	{
		ret[index_ret] = s[index];
		index++;
		index_ret++;
	}
	ret[index_ret] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = (s_len - start);
	if ((start > s_len) || (s[0] == 0))
	{
		ret = (char *)malloc(sizeof(char));
		if (!(ret))
			return (0);
		ret[0] = '\0';
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!(ret))
		return (0);
	ret = ft_s_to_ret(ret, s, start, len);
	return (ret);
}
