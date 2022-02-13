/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:59:48 by alalonzo          #+#    #+#             */
/*   Updated: 2017/03/20 16:13:12 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_params(int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*new;

	i = 1;
	if (ac - 1 == 0 || !av || !(new = ft_lstnew(av[i], ft_strlen(av[i]))))
	{
		return (NULL);
	}
	head = new;
	while (++i < ac)
	{
		ft_lstadd_back(&new, av[i]);
	}
	return (head);
}
