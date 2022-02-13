/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:53:08 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:26:37 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_has_nul(const char *src, size_t size)
{
	size_t	cur;

	cur = 0;
	while (cur < size)
	{
		if (src[cur] == '\0')
		{
			return (1);
		}
		cur++;
	}
	return (0);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	if (i < size)
	{
		j = 0;
		while (i + j < size - 1 && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
		if (ft_has_nul(src, size) == 1)
		{
			dst[i + j] = '\0';
		}
		return (i + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
