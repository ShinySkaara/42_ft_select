/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:24:35 by alalonzo          #+#    #+#             */
/*   Updated: 2017/04/02 18:06:27 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tab;

	if ((tab = (void *)malloc(sizeof(*tab) * size)) != NULL)
	{
		ft_memset(tab, 0, size);
	}
	return (tab);
}
