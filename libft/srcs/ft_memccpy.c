/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:09:26 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:20:49 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			cur;
	unsigned char	*dst2;
	unsigned char	*src2;

	cur = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (cur < n)
	{
		dst2[cur] = src2[cur];
		if (src2[cur] == (unsigned char)c)
		{
			return (dst + cur + 1);
		}
		cur++;
	}
	return (NULL);
}
