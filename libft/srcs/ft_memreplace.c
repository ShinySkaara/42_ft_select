/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:01:22 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:22:46 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memreplace(void *ptr, int f, int r, size_t size)
{
	size_t			i;
	unsigned char	*dst;

	dst = (unsigned char *)ptr;
	if (ptr && size)
	{
		i = 0;
		while (i < size)
		{
			if (dst[i] == f)
			{
				dst[i] = r;
			}
			i++;
		}
	}
	return (ptr);
}
