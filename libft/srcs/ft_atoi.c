/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:21:21 by alalonzo          #+#    #+#             */
/*   Updated: 2017/04/10 15:26:58 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		is_negative;
	int		nb;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
	{
		str++;
	}
	is_negative = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = 1;
		str++;
	}
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (is_negative == 1)
		nb = nb * -1;
	return (nb);
}
