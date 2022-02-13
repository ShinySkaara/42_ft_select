/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:27:07 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:23:06 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrev(void *ptr, size_t where, size_t size)
{
	unsigned char	*dst;
	char			temp;

	dst = (unsigned char *)ptr;
	if (dst && size && where < size)
	{
		while (where < size)
		{
			temp = dst[where];
			dst[where] = dst[size];
			dst[size] = temp;
			where++;
			size--;
		}
	}
	return (ptr);
}
