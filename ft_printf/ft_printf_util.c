/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 06:59:49 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/05/01 11:56:33 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (s == 0)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_putchar_pf(char c)
{
	int	error;

	error = write(1, &c, 1);
	if (error == -1)
		return (-1);
	return (sizeof(char));
}

int	ft_putstr_pf(char *s)
{
	int	len;
	int	error;

	if (s == 0)
	{
		error = write(1, "(null)", 6);
		if (error == -1)
			return (-1);
		return (6);
	}
	len = 0;
	len = ft_strlen(s);
	error = write(1, s, len);
	if (error == -1)
		return (-1);
	return (len);
}

static size_t	ft_get_len(unsigned long long addr, size_t *len)
{
	while (addr > 0)
	{
		(*len)++;
		addr = addr / 16;
	}
	return (*len);
}

char	*ft_print_addr(unsigned long long addr)
{
	size_t				index;
	char				*ret;

	index = 2;
	if (addr == 0)
		index++;
	index = ft_get_len(addr, &index);
	ret = (char *)malloc(sizeof(char) * index + 1);
	if (!ret)
		return (0);
	ret[index] = '\0';
	if (addr == 0)
		ret[--index] = '0';
	while (addr)
	{
		ret[--index] = "0123456789abcdef"[addr % 16];
		addr = addr / 16;
	}
	ret[--index] = 'x';
	ret[--index] = '0';
	return (ret);
}
