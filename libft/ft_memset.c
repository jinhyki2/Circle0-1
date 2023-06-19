/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:42:31 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/26 11:36:52 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		ptr[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
