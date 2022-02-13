/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:09:57 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:12:03 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_value(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n >= 0 && n <= 9)
	{
		return (0);
	}
	return (1);
}

static int		ft_itoa_len(long int nbr)
{
	int		len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

static long int	ft_itoa_split(long int nbr)
{
	long int	number;

	number = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
	}
	if (nbr >= 0 && nbr <= 9)
	{
		return (nbr);
	}
	while (nbr > 0)
	{
		number = (number * 10) + (nbr % 10);
		nbr = nbr / 10;
	}
	return (number);
}

static char		*ft_itoa_convert(int value, int len, long int nbr)
{
	char	*tab;
	int		cur;

	if ((tab = ft_strnew(len)) == NULL)
		return (NULL);
	cur = 0;
	if (value == -1)
	{
		tab[cur++] = '-';
		len--;
	}
	if (value == 0)
	{
		tab[cur++] = (nbr % 10) + '0';
		len--;
	}
	while (len > 0)
	{
		tab[cur++] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	tab[cur] = '\0';
	return (tab);
}

char			*ft_itoa(int n)
{
	long int	nbr;
	int			value;
	int			len;

	nbr = (long int)n;
	value = ft_itoa_value(n);
	len = ft_itoa_len(nbr);
	nbr = ft_itoa_split(nbr);
	return (ft_itoa_convert(value, len, nbr));
}
