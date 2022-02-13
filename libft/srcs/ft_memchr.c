/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:29:04 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:21:09 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cur;
	unsigned char	*str;

	str = (unsigned char *)s;
	cur = 0;
	while (cur < n)
	{
		if (str[cur] == (unsigned char)c)
		{
			return ((void *)s + cur);
		}
		cur++;
	}
	return (NULL);
}
