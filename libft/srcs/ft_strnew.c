/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:23:54 by alalonzo          #+#    #+#             */
/*   Updated: 2017/04/02 19:00:20 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	if ((tab = (char *)malloc(sizeof(char) * (size + 1))) != NULL)
	{
		ft_memset((void *)tab, 0, size + 1);
	}
	return (tab);
}
