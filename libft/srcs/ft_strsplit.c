/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:53:30 by alalonzo          #+#    #+#             */
/*   Updated: 2019/02/04 17:49:06 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(const char *s, int c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			s = ft_strchrnul(s, c);
		}
	}
	return (i);
}

static char		**ft_matrice_new(int size)
{
	char	**row;

	if ((row = (char **)malloc(sizeof(char *) * (size + 1))))
		row[size] = NULL;
	return (row);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	char	*tmp;
	char	**tab;

	tab = NULL;
	if (s && (tab = ft_matrice_new(ft_word_count(s, c))))
	{
		i = 0;
		while (*s)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				tmp = ft_strchrnul(s, c);
				tab[i++] = ft_strsub(s, 0, (tmp - s));
				s = tmp;
			}
		}
	}
	return (tab);
}
