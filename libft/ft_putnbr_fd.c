/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:24:23 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/04/30 17:22:31 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nbr(long long integer, int fd)
{
	unsigned char	c;

	if (integer > 0)
	{
		c = integer % 10 + '0';
		ft_print_nbr(integer / 10, fd);
		ft_putchar_fd(c, fd);
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	integer;

	integer = (long long)n;
	if (integer == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (integer < 0)
	{
		integer = -integer;
		write (fd, "-", 1);
	}
	ft_print_nbr(integer, fd);
	return ;
}
