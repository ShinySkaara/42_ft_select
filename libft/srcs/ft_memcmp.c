/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:42:02 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:21:50 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cur;
	unsigned char	*str1;
	unsigned char	*str2;

	cur = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (cur < n)
	{
		if (str1[cur] != str2[cur])
		{
			return (str1[cur] - str2[cur]);
		}
		cur++;
	}
	return (0);
}
