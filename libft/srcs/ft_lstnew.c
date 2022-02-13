/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:02:00 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:19:40 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*this;

	if (!(this = (t_list *)malloc(sizeof(t_list))))
	{
		return (NULL);
	}
	if (content)
	{
		if (!(this->content = (void *)malloc(content_size)))
		{
			free(this);
			return (NULL);
		}
		ft_memcpy(this->content, content, content_size);
		this->content_size = content_size;
	}
	else
	{
		this->content = NULL;
		this->content_size = 0;
	}
	this->next = NULL;
	return (this);
}
