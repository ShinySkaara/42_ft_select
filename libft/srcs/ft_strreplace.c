/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:43:10 by alalonzo          #+#    #+#             */
/*   Updated: 2016/11/23 12:50:46 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strreplace(char *str, char s, char r)
{
	unsigned int	cur;

	if (str && s && r)
	{
		cur = 0;
		while (str[cur] != '\0')
		{
			if (str[cur] == s)
			{
				str[cur] = r;
			}
			cur++;
		}
	}
	return (str);
}
