/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:01:56 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/25 18:52:52 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst == 0)
		return ;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->next == 0)
		{
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
	if (*lst == 0)
		*lst = new;
	return ;
}
