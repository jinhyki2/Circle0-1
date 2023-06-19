/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:23:00 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/23 19:34:34 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	index;

	index = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	else
	{
		while ((src[index] != '\0') && ((len_dst + index + 1) < dstsize))
		{
			dst[len_dst + index] = src[index];
			index++;
		}
		dst[len_dst + index] = '\0';
		return (len_dst + len_src);
	}
}
