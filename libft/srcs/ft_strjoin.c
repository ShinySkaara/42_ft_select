/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:21:41 by alalonzo          #+#    #+#             */
/*   Updated: 2017/04/03 18:32:30 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	char	*end;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 != NULL && s2 != NULL && (str = ft_strnew(len)) != NULL)
	{
		ft_strcpy(str, s1);
		end = ft_strchr(str, '\0');
		ft_strcpy(end, s2);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
