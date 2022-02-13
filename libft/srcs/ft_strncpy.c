/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:06:23 by alalonzo          #+#    #+#             */
/*   Updated: 2017/04/02 19:20:37 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*str;

	str = dst;
	while (*src != '\0' && len > 0)
	{
		*str++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*str++ = '\0';
		len--;
	}
	return (dst);
}
