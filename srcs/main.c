/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:08:52 by alalonzo          #+#    #+#             */
/*   Updated: 2019/07/21 20:44:31 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

static int		st_count_args(char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (argv[i])
		if (argv[i++][0] != '\0')
			j++;
	return (j);
}

static int		st_init(int count)
{
	int		ret;
	char	*term_name;
	char	*name;

	ret = 0;
	if (count == 0)
		ft_putstr_fd(NOARG, 2);
	else if ((term_name = getenv("TERM")) == NULL)
		ft_putstr_fd(NOENV, 2);
	else if (tgetent(NULL, term_name) < 1)
		ft_putstr_fd(NOTERM, 2);
	else if ((name = ttyname(0)) == NULL)
		ft_putstr_fd(NONAME, 2);
	else if ((g_env.fd = open(name, O_RDWR)) < 0)
		ft_putstr_fd(NOFD, 2);
	else
		ret = 1;
	return (ret);
}

static int		st_init_bis(char **t)
{
	int		i;

	i = 0;
	t[TERM_TI] = tgetstr("ti", NULL);
	t[TERM_TE] = tgetstr("te", NULL);
	t[TERM_VI] = tgetstr("vi", NULL);
	t[TERM_VS] = tgetstr("vs", NULL);
	t[TERM_CM] = tgetstr("cm", NULL);
	t[TERM_US] = tgetstr("us", NULL);
	t[TERM_MR] = tgetstr("mr", NULL);
	t[TERM_ME] = tgetstr("me", NULL);
	while (i < TERM_COUNT)
		if (t[i++] == NULL)
			return (0);
	return (1);
}

static t_arg	*st_tab_args(int count, char **argv)
{
	int		i;
	int		j;
	t_arg	*arg;

	if ((arg = (t_arg *)malloc(sizeof(t_arg) * count)))
	{
		i = 1;
		j = 0;
		while (argv[i])
		{
			if (argv[i][0] != '\0')
			{
				arg[j].name = argv[i];
				arg[j].status = 0;
				arg[j].len = ft_strlen(argv[i]);
				j++;
			}
			i++;
		}
	}
	else
		ft_putstr_fd(NOMEM, 2);
	return (arg);
}

int				main(int argc, char *argv[])
{
	g_env.count = st_count_args(argv);
	if ((st_init(g_env.count)))
	{
		if ((st_init_bis(g_env.t)))
		{
			if ((g_env.arg = st_tab_args(g_env.count, argv)))
			{
				if (tcgetattr(0, &g_env.term) == 0)
					second();
				free(g_env.arg);
			}
		}
		else
			ft_putstr_fd(NOLOAD, 2);
	}
	return (argc * 0);
}
