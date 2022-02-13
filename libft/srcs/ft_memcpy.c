/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:23:14 by alalonzo          #+#    #+#             */
/*   Updated: 2017/04/02 18:13:02 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (n > 0)
	{
		*dst2++ = *src2++;
		n--;
	}
	return (dst);
}
