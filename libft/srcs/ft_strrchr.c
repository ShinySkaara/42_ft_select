/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:37:37 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:28:48 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	cur;
	size_t	i;
	char	*str;

	cur = 0;
	i = 0;
	str = (char *)s;
	while (str[cur] != '\0')
	{
		if (str[cur] == c)
		{
			i = cur;
		}
		cur++;
	}
	if (str[i] == c)
	{
		return (str + i);
	}
	if (str[cur] == c)
	{
		return (str + cur);
	}
	return (NULL);
}
