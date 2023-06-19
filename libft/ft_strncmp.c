/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:31:32 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/23 19:42:16 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	index = 0;
	while (((ptr_s1[index] != '\0') || (ptr_s2[index] != '\0')) && (index < n))
	{
		if (ptr_s1[index] != ptr_s2[index])
			return (ptr_s1[index] - ptr_s2[index]);
		index++;
	}
	return (0);
}
