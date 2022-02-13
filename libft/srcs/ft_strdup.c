/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:03:43 by alalonzo          #+#    #+#             */
/*   Updated: 2017/04/03 18:39:32 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	if (s != NULL && (str = ft_strnew(len)) != NULL)
	{
		str = ft_strcpy(str, s);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
