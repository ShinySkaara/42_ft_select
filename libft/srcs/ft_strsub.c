/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:02:35 by alalonzo          #+#    #+#             */
/*   Updated: 2017/04/03 17:45:49 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;

	if (s != NULL && (tab = ft_strnew(len)) != NULL)
	{
		ft_strncpy(tab, s + start, len);
		tab[len] = '\0';
		return (tab);
	}
	return (NULL);
}
