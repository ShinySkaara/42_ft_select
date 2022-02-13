/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:52:04 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/08 12:23:19 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			temp;

	if (str)
	{
		j = 0;
		while (str[j] != '\0')
		{
			j++;
		}
		j--;
		i = 0;
		while (i < j)
		{
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			i++;
			j--;
		}
	}
	return (str);
}
