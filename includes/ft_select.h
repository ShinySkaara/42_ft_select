/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:12:20 by alalonzo          #+#    #+#             */
/*   Updated: 2019/07/21 20:44:54 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>

# define NOARG	"usage: ./ft_select arg ...\n"
# define NOTTY	"output is not a valid tty.\n"
# define NOENV	"tty descriptor not found.\n"
# define NOTERM	"terminfo database could not be found.\n"
# define NOMEM	"could not allocate memory.\n"
# define NOLOAD	"could not load termcap.\n"
# define NONAME	"could not resolve term name.\n"
# define NOFD	"could not resolve term file descriptor.\n"

# define K_CTRLD	4
# define K_RETURN	10
# define K_ESCAPE	27
# define K_SPACE	32
# define K_DEL		127
# define K_UP		4283163
# define K_DOWN		4348699
# define K_RIGHT	4414235
# define K_LEFT		4479771

enum				e_term
{
	TERM_TI,
	TERM_TE,
	TERM_VI,
	TERM_VS,
	TERM_CM,
	TERM_US,
	TERM_MR,
	TERM_ME,
	TERM_COUNT
};

typedef struct		s_arg
{
	char			*name;
	char			status;
	int				len;
}					t_arg;

typedef struct		s_env
{
	char			*t[TERM_COUNT];
	t_arg			*arg;
	int				count;
	int				at;
	int				key;
	struct termios	term;
	int				x;
	int				y;
	int				len;
	int				epl;
	int				fd;
}					t_env;

t_env				g_env;

void				second(void);
int					st_putchar(int c);
void				st_term_set(void);
void				st_term_unset(void);
int					st_key_handler(void);
int					st_term_handler(void);
void				st_sig_master(void);

#endif
