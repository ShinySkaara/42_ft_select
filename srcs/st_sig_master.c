/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_sig_master.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:02:58 by alalonzo          #+#    #+#             */
/*   Updated: 2019/07/21 20:55:38 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

static void	st_sig_stop(int sig)
{
	st_term_unset();
	free(g_env.arg);
	exit(sig);
}

static void	st_sig_resize(int sig)
{
	sig = 0;
	st_term_handler();
}

static void	st_sig_break(int sig)
{
	char	cmd[2];

	cmd[0] = g_env.term.c_cc[VSUSP];
	cmd[1] = '\0';
	st_term_unset();
	ioctl(0, TIOCSTI, cmd);
	signal(sig, SIG_DFL);
}

static void	st_sig_continue(int sig)
{
	st_term_set();
	st_term_handler();
	signal(SIGTSTP, st_sig_break);
	sig = 0;
}

void		st_sig_master(void)
{
	int		i;

	i = 0;
	while (i < NSIG)
	{
		if (i != SIGFPE && i != SIGBUS && i != SIGSEGV)
		{
			if (i == SIGWINCH)
				signal(i, st_sig_resize);
			else if (i == SIGTSTP || i == SIGSTOP)
				signal(i, st_sig_break);
			else if (i == SIGCONT)
				signal(i, st_sig_continue);
			else
				signal(i, st_sig_stop);
		}
		i++;
	}
}
