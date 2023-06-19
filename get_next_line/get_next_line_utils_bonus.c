/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:31:00 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/05/01 14:21:15 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (s == 0)
		return (0);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	if (*ptr == (unsigned char)c)
		return (ptr);
	return (0);
}

size_t	ft_strlen_gnl(const char *s, char c)
{
	size_t	len;

	len = 0;
	if (s == 0)
		return (0);
	while (s[len] != c)
		len++;
	return (len);
}

static char	*ft_strcpy(char *dst, char const *src, size_t *index_continue)
{
	size_t	index;

	index = 0;
	if (src == 0)
		return (dst);
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
	size_t	index;
	char	*ret;

	total_len = 0;
	index = 0;
	total_len = ft_strlen_gnl(s1, '\0') + ft_strlen_gnl(s2, '\0');
	if (total_len == 0)
		return (0);
	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!(ret))
		return (0);
	index = 0;
	ret = ft_strcpy(ret, s1, &index);
	ret = ft_strcpy(ret, s2, &index);
	ret[index] = '\0';
	return (ret);
}

char	*ft_strdup_gnl(const char *s1)
{
	size_t	len;
	size_t	index;
	char	*ret;

	len = 0;
	if (s1 == 0)
		return (0);
	len = ft_strlen_gnl(s1, '\0');
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ret))
		return (0);
	index = 0;
	while (index < len)
	{
		ret[index] = s1[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
