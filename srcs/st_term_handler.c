/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_term_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:02:32 by alalonzo          #+#    #+#             */
/*   Updated: 2019/07/21 20:50:11 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

static int	st_term_capabilities(void)
{
	int		tmp;

	g_env.epl = g_env.x / g_env.len;
	if (g_env.epl)
	{
		while ((tmp = (g_env.epl * g_env.len) + (g_env.epl - 1)) > g_env.x)
			g_env.epl--;
		tmp = g_env.epl * g_env.y;
		if (g_env.count <= tmp)
			return (1);
	}
	return (0);
}

static void	st_term_print_style(int i)
{
	if (g_env.at == i && g_env.arg[i].status == 1)
	{
		tputs(g_env.t[TERM_MR], 1, st_putchar);
		tputs(g_env.t[TERM_US], 1, st_putchar);
		write(g_env.fd, g_env.arg[i].name, g_env.arg[i].len);
		tputs(g_env.t[TERM_ME], 1, st_putchar);
	}
	else if (g_env.arg[i].status == 1)
	{
		tputs(g_env.t[TERM_US], 1, st_putchar);
		write(g_env.fd, g_env.arg[i].name, g_env.arg[i].len);
		tputs(g_env.t[TERM_ME], 1, st_putchar);
	}
	else if (g_env.at == i)
	{
		tputs(g_env.t[TERM_MR], 1, st_putchar);
		write(g_env.fd, g_env.arg[i].name, g_env.arg[i].len);
		tputs(g_env.t[TERM_ME], 1, st_putchar);
	}
	else
	{
		write(g_env.fd, g_env.arg[i].name, g_env.arg[i].len);
	}
}

static void	st_term_print(void)
{
	char	*cur;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (i < g_env.count)
	{
		cur = tgoto(g_env.t[TERM_CM], x, y);
		tputs(cur, 1, st_putchar);
		st_term_print_style(i);
		x += g_env.len + 1;
		if ((x + g_env.len) >= g_env.x)
		{
			x = 0;
			y++;
		}
		i++;
	}
}

static void	st_term_clear(void)
{
	struct ttysize	ts;
	char			*cur;
	char			buf[4096];
	int				i;

	ioctl(0, TIOCGSIZE, &ts);
	g_env.len = 0;
	g_env.x = ts.ts_cols;
	g_env.y = ts.ts_lines;
	cur = tgoto(g_env.t[TERM_CM], 0, 0);
	tputs(cur, 1, st_putchar);
	i = 0;
	while (i < g_env.x)
		buf[i++] = ' ';
	i = 0;
	while (i < g_env.y)
	{
		write(g_env.fd, buf, g_env.x);
		i++;
	}
}

int			st_term_handler(void)
{
	int				i;

	i = 0;
	st_term_clear();
	while (i < g_env.count)
	{
		if (g_env.arg[i].len > g_env.len)
			g_env.len = g_env.arg[i].len;
		i++;
	}
	if (i > 0)
	{
		if (st_term_capabilities())
			st_term_print();
		return (1);
	}
	return (0);
}
