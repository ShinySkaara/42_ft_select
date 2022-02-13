/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:01:00 by alalonzo          #+#    #+#             */
/*   Updated: 2019/02/03 20:29:26 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*gnl_join(char *s1, char *s2)
{
	char	*str;

	if ((str = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	ft_strdel(&s1);
	return (str);
}

char	*gnl_line(char **src)
{
	char	*str;
	char	*tmp;
	char	*n;
	size_t	len;

	n = ft_strchrnul(*src, '\n');
	len = ft_strlen(*src) - ft_strlen(n);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	str = ft_strncpy(str, *src, len);
	if (*n != '\0')
	{
		len = ft_strlen(n + 1);
		if ((tmp = ft_strnew(len)) == NULL)
			return (NULL);
		tmp = ft_strncpy(tmp, n + 1, len);
		ft_strdel(src);
		*src = tmp;
	}
	else
	{
		ft_strdel(src);
		*src = NULL;
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*tmp = NULL;

	if (line == NULL || (tmp == NULL && (tmp = ft_strnew(0)) == NULL))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((tmp = gnl_join(tmp, buff)) == NULL ||
				ft_strchr(buff, '\n') != NULL)
			break ;
	}
	if (ret < 0 || tmp == NULL)
		return (-1);
	if (tmp != NULL && *tmp != '\0')
	{
		if ((*line = gnl_line(&tmp)) == NULL)
			return (-1);
		return (1);
	}
	return (0);
}
