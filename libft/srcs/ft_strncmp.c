/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:24:20 by alalonzo          #+#    #+#             */
/*   Updated: 2017/08/08 17:25:43 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cur;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	cur = 0;
	if (str1 && str2)
	{
		if (n == 0)
		{
			return (0);
		}
		while (cur < n - 1 && str1[cur] && str2[cur] && str1[cur] == str2[cur])
		{
			cur++;
		}
	}
	return (str1[cur] - str2[cur]);
}
