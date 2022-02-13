/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:23:13 by alalonzo          #+#    #+#             */
/*   Updated: 2019/07/22 17:46:43 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

int			st_putchar(int c)
{
	write(g_env.fd, &c, 1);
	return (c);
}

static void	st_print_result(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < g_env.count)
	{
		if (g_env.arg[i].status == 1)
			j++;
		i++;
	}
	i = 0;
	while (j > 0)
	{
		if (g_env.arg[i].status == 1)
		{
			write(1, g_env.arg[i].name, g_env.arg[i].len);
			if (--j)
				ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
}

void		second(void)
{
	st_sig_master();
	st_term_set();
	g_env.at = 0;
	while (1)
	{
		g_env.key = 0;
		if (st_term_handler() == 0 || st_key_handler() < 1)
			break ;
	}
	st_term_unset();
	if (g_env.key == K_RETURN)
		st_print_result();
}
