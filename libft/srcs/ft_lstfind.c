/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:43:17 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:14:28 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *find, int (*cmp)())
{
	if (!lst || !find || !(*cmp))
	{
		return (NULL);
	}
	while (lst != NULL)
	{
		if ((*cmp)(lst->content, find) == 0)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}
