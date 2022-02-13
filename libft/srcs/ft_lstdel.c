/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:03:59 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:13:27 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next;

	if (!alst || !del)
		return ;
	list = *alst;
	while (list)
	{
		next = list->next;
		(*del)(list->content, list->content_size);
		free(list);
		list = next;
	}
	*alst = NULL;
}
