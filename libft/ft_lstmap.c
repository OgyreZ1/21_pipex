/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:59:51 by yironmak          #+#    #+#             */
/*   Updated: 2021/10/12 11:59:51 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_start;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	new_start = new;
	while (lst->next)
	{
		new->next = ft_lstnew(f(lst->next->content));
		if (new->next == NULL)
		{
			ft_lstclear(&new_start, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (new_start);
}
