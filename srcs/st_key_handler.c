/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:30:45 by alalonzo          #+#    #+#             */
/*   Updated: 2019/07/16 16:27:51 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

static void	st_key_spc_rgt_lft(int key)
{
	if (key == K_SPACE)
		g_env.arg[g_env.at].status = ++g_env.arg[g_env.at].status % 2;
	if (key == K_SPACE || key == K_RIGHT)
		g_env.at = ++g_env.at % g_env.count;
	if (key == K_LEFT)
		if (--g_env.at < 0)
			g_env.at += g_env.count;
}

static void	st_key_up_down(int key)
{
	int		i;

	if (key == K_DOWN)
		if ((g_env.at += g_env.epl) > g_env.count - 1)
			g_env.at = g_env.at % g_env.epl;
	if (key == K_UP)
	{
		i = 0;
		while ((i * g_env.epl) < g_env.count)
			i++;
		i = i * g_env.epl;
		g_env.at -= g_env.epl;
		if (g_env.at < 0)
			g_env.at += i;
		while (g_env.at > g_env.count)
			g_env.at -= g_env.epl;
	}
}

static void	st_key_del(void)
{
	int		i;

	i = g_env.at;
	while (i < g_env.count - 1)
	{
		g_env.arg[i] = g_env.arg[i + 1];
		i++;
	}
	g_env.count--;
	if (g_env.at >= g_env.count)
		g_env.at--;
}

int			st_key_handler(void)
{
	int		ret;
	int		key;

	key = 0;
	if ((ret = read(0, &key, sizeof(int))) > 0)
	{
		if (key == K_CTRLD || key == K_ESCAPE || key == K_RETURN)
		{
			g_env.key = key == K_RETURN ? K_RETURN : 0;
			ret = 0;
		}
		if (key == K_SPACE || key == K_RIGHT || key == K_LEFT)
			st_key_spc_rgt_lft(key);
		if (key == K_DOWN || key == K_UP)
			st_key_up_down(key);
		if (key == K_DEL)
			st_key_del();
	}
	return (ret);
}
