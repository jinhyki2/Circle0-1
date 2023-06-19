/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:19:54 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/03/26 16:47:47 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_new(t_list *lst, void *(*f)(void *),
		void (*del)(void *), t_list *s)
{
	void	*input_content;
	t_list	*new_lst;
	t_list	*tmp_lst;

	tmp_lst = s;
	while (lst)
	{
		input_content = (*f)(lst->content);
		new_lst = ft_lstnew(input_content);
		if (!(new_lst))
		{
			free(input_content);
			ft_lstclear(&s, del);
			if (del == 0)
				ft_lstclear(&s, free);
			return (0);
		}
		tmp_lst->next = new_lst;
		tmp_lst = tmp_lst->next;
		lst = lst->next;
	}
	tmp_lst->next = 0;
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	void	*input_content;
	int		alloc_check;

	if (lst == 0 || f == 0)
		return (0);
	input_content = (*f)(lst->content);
	start = ft_lstnew(input_content);
	if (start == 0)
	{
		free(input_content);
		return (0);
	}
	lst = lst->next;
	alloc_check = ft_set_new(lst, (*f), del, start);
	if (alloc_check == 0)
		return (0);
	return (start);
}
