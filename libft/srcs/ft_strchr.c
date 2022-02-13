/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:14:44 by alalonzo          #+#    #+#             */
/*   Updated: 2017/04/03 18:48:24 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (s != NULL)
	{
		str = (char *)s;
		while (*str != '\0' && *str != c)
		{
			str++;
		}
		if (*str == c)
		{
			return (str);
		}
	}
	return (NULL);
}
