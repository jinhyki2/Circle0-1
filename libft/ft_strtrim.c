/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:26:03 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/26 16:48:50 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(unsigned char c, char const *set)
{
	size_t			index;
	unsigned char	*ptr_set;

	index = 0;
	ptr_set = (unsigned char *)set;
	while (ptr_set[index] != '\0')
	{
		if (c == ptr_set[index])
			return (1);
		index++;
	}
	return (0);
}

static size_t	ft_cal_retlen(char const *s1, char const *set, size_t *i_end)
{
	size_t			index;
	size_t			ret_len;
	unsigned char	*ptr_s1;
	size_t			s1_len;

	ptr_s1 = (unsigned char *)s1;
	s1_len = ft_strlen(s1);
	index = 0;
	ret_len = s1_len;
	while ((index < s1_len) && (ft_is_set(ptr_s1[index], set) == 1))
	{
		index++;
		ret_len--;
	}
	if (ret_len == 0)
		return (ret_len);
	index = s1_len - 1;
	while ((index >= 0) && (ft_is_set(ptr_s1[index], set) == 1))
	{
		index--;
		ret_len--;
	}
	*i_end = index;
	return (ret_len);
}

static char	*ft_trimcpy(char *ret, char const *s1,
		char const *set, size_t index_end)
{
	size_t			index;
	size_t			index_ret;
	unsigned char	*ptr_s1;

	ptr_s1 = (unsigned char *)s1;
	index = 0;
	index_ret = 0;
	while ((index <= index_end) && (ft_is_set(ptr_s1[index], set) == 1))
		index++;
	while (index <= index_end)
	{
		ret[index_ret] = ptr_s1[index];
		index++;
		index_ret++;
	}
	ret[index_ret] = '\0';
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	index_end;
	char	*ret;

	len = ft_cal_retlen(s1, set, &index_end);
	if (len <= 0)
	{
		ret = (char *)malloc(1);
		if (!(ret))
			return (0);
		ret[0] = '\0';
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ret))
		return (0);
	ret = ft_trimcpy(ret, s1, set, index_end);
	return (ret);
}
