/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:22:01 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:12:41 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, void *data)
{
	size_t	data_size;
	t_list	*new;
	t_list	*last;

	data_size = ft_strlen((char *)data);
	if (!alst || !(new = ft_lstnew(data, data_size)))
	{
		return ;
	}
	last = ft_lstlast(*alst);
	last->next = new;
}
