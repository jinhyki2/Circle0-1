/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:31:08 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/05/01 12:06:11 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_and_free(char *str)
{
	int	ret;

	if (str == 0)
		return (-1);
	ret = ft_putstr_pf(str);
	free(str);
	return (ret);
}

static int	ft_flagcheck_and_print(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	if (c == '%')
		return (ft_putchar_pf('%'));
	else
		return (-1);
}

static int	ft_flagcheck_and_print_etc(char c, va_list args)
{
	char	*str;

	if (c == 'p')
	{
		str = ft_print_addr(va_arg(args, unsigned long long));
		return (ft_print_and_free(str));
	}
	if ((c == 'd') || (c == 'i'))
	{
		str = ft_itoa((long long)va_arg(args, int));
		return (ft_print_and_free(str));
	}
	if (c == 'u')
	{
		str = ft_uitoa(va_arg(args, unsigned int));
		return (ft_print_and_free(str));
	}
	if (c == 'x' || c == 'X')
	{
		str = ft_itoah(va_arg(args, unsigned int), c);
		return (ft_print_and_free(str));
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		t_len;

	t_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 's' || *format == '%')
				ret = ft_flagcheck_and_print(*format, args);
			else
				ret = ft_flagcheck_and_print_etc(*format, args);
		}
		else
			ret = ft_putchar_pf(*format);
		if (ret == -1)
			return (-1);
		t_len += ret;
		format++;
	}
	va_end(args);
	return (t_len);
}
