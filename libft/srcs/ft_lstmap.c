/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:08:10 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:16:43 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*save;
	t_list	*new;
	t_list	*origin;

	save = NULL;
	new = NULL;
	origin = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		if (lst != NULL)
		{
			new = ft_lstnew(lst->content, lst->content_size);
			new = f(new);
		}
		if (save != NULL)
			save->next = new;
		save = new;
		if (origin == NULL)
			origin = new;
		lst = lst->next;
	}
	return (origin);
}
