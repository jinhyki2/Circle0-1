/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:25:42 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/25 19:27:23 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ret;

	ret = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			ret = ptr;
		ptr++;
	}
	if (ret != 0)
		return (ret);
	else if ((*ptr == '\0') && (*ptr == (char)c))
	{
		ret = ptr;
		return (ret);
	}
	return (0);
}
