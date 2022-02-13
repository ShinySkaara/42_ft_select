/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:32:37 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:14:15 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, size_t n)
{
	size_t	i;

	if (!lst)
	{
		return (NULL);
	}
	i = 0;
	while (i++ < n && n > 0 && lst != NULL)
	{
		lst = lst->next;
	}
	if (i < n && n > 0)
	{
		return (NULL);
	}
	return (lst);
}
