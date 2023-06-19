/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:58:26 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/23 19:44:00 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	index_f;
	char	*ptr;

	ptr = (char *)haystack;
	index = 0;
	if (needle[0] == 0)
		return (ptr);
	while ((ptr[index] != '\0') && (index < len))
	{
		index_f = 0;
		while ((needle[index_f] == ptr[index + index_f])
			&& (ptr[index + index_f] != '\0' && ((index + index_f) < len)))
		{
			index_f++;
			if (needle[index_f] == '\0')
				return (&ptr[index]);
		}
		index++;
	}
	return (0);
}
