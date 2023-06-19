/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:10:20 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/25 19:14:01 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				index;
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (const unsigned char *)src;
	if (temp_src < temp_dst)
	{
		index = 1;
		while (index <= len)
		{
			temp_dst[len - index] = temp_src[len - index];
			index++;
		}
	}
	else if (temp_src > temp_dst)
	{
		index = 0;
		while (index < len)
		{
			temp_dst[index] = temp_src[index];
			index++;
		}
	}
	return (dst);
}
