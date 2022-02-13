/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_term_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:03 by alalonzo          #+#    #+#             */
/*   Updated: 2019/07/16 16:44:25 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	st_term_set(void)
{
	struct termios	term;

	term = g_env.term;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tputs(g_env.t[TERM_TI], 1, st_putchar);
	tputs(g_env.t[TERM_VI], 1, st_putchar);
	tcsetattr(0, TCSADRAIN, &term);
}

void	st_term_unset(void)
{
	struct termios	term;

	term = g_env.term;
	tputs(g_env.t[TERM_TE], 1, st_putchar);
	tputs(g_env.t[TERM_VS], 1, st_putchar);
	tcsetattr(0, TCSANOW, &term);
}
