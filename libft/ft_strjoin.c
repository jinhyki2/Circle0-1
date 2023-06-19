/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:25:18 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/26 16:38:01 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcopy(char *dst, char const *src, size_t *index_continue)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[*index_continue] = src[index];
		(*index_continue)++;
		index++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	len_s1;
	size_t	len_s2;
	size_t	index;
	char	*ret;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_len = len_s1 + len_s2;
	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!(ret))
		return (0);
	index = 0;
	ret = ft_strcopy(ret, s1, &index);
	ret = ft_strcopy(ret, s2, &index);
	ret[index] = '\0';
	return (ret);
}
