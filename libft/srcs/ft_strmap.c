/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:36:24 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:27:04 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	cur;
	char	*tab;

	if (s)
	{
		len = ft_strlen(s);
		if (!(tab = ft_strnew(len)))
		{
			return (NULL);
		}
		cur = 0;
		while (s[cur] != '\0')
		{
			tab[cur] = (*f)(s[cur]);
			cur++;
		}
		tab[cur] = '\0';
		return (tab);
	}
	return (NULL);
}
