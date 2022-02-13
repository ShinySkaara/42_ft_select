/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:17:05 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:27:16 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			tab[cur] = (*f)(cur, s[cur]);
			cur++;
		}
		return (tab);
	}
	return (NULL);
}
