/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:30:14 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:28:34 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	cur;
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)big;
	str2 = (char *)little;
	if (ft_strlen(str2) == 0)
		return (str1);
	cur = 0;
	while (str1[cur] != '\0')
	{
		i = 0;
		while (cur + i < n && str1[cur + i] == str2[i] && str2[i] != '\0')
		{
			i++;
		}
		if (str2[i] == '\0')
		{
			return (str1 + cur);
		}
		cur++;
	}
	return (NULL);
}
