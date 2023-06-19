/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:48:02 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/05/01 11:13:52 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *s);
char	*ft_print_addr(unsigned long long addr);
char	*ft_itoa(int n);
char	*ft_uitoa(int n);
char	*ft_itoah(unsigned int n, char c);

#endif
