/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:09:56 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:14:44 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstforeach(t_list *lst, void (*f)(void *))
{
	if (!lst || !(*f))
	{
		return ;
	}
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
