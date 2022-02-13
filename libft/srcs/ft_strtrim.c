/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:03:50 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:29:52 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	j;
	char	*tab;

	if (s)
	{
		i = 0;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
			i++;
		j = ft_strlen(s) - 1;
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > 0)
			j--;
		if (i < ft_strlen(s))
		{
			if (!(tab = ft_strnew(j - i + 1)))
				return (NULL);
			ft_strncpy(tab, s + i, j - i + 1);
			return (tab);
		}
		if (!(tab = ft_strnew(0)))
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	return (NULL);
}
