/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:24:47 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/26 16:37:40 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_all_free(char **arr_for_free, size_t last)
{
	size_t	index;

	index = 0;
	while (index <= last && last != 0)
	{
		free(arr_for_free[index]);
		index++;
	}
	free(arr_for_free);
	return ;
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		while ((s[index] == c) && (s[index] != '\0'))
			index++;
		if ((s[index] != c) && (s[index] != '\0'))
			count++;
		while ((s[index] != c) && (s[index] != '\0'))
			index++;
	}
	return (count);
}

static char	*ft_strcpy(char *dst, char *src, size_t index_src, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		dst[index] = src[index_src];
		index++;
		index_src++;
	}
	dst[index] = '\0';
	return (dst);
}

static char	**ft_do_split(char **ret, char const *s, char c, size_t size)
{
	size_t	i;
	size_t	index;
	size_t	index_s;

	i = 0;
	index = 0;
	while ((s[i] != '\0') && (index < size))
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		index_s = i;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
		ret[index] = (char *)malloc(sizeof(char) * (i - index_s + 1));
		if (!(ret[index]))
		{
			ft_all_free(ret, index);
			return (0);
		}
		ret[index] = ft_strcpy(ret[index], (char *)s, index_s, i - index_s);
		index++;
	}
	ret[index] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**ret;

	size = ft_count_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!(ret))
	{
		ft_all_free(ret, 0);
		return (0);
	}
	if (size == 0)
	{
		ret[0] = 0;
		return (ret);
	}
	ret = ft_do_split(ret, s, c, size);
	return (ret);
}
