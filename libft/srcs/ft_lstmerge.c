/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:42:56 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:19:25 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **lst1, t_list **lst2)
{
	t_list	*last;

	if (!lst1 || !lst2)
	{
		return ;
	}
	last = ft_lstlast(*lst1);
	last->next = *lst2;
}
