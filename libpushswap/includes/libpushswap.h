/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:54:09 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 14:54:29 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <libft.h>
# include <ps_struct.h>

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# define NB_ACT 11

# define OKI 1
# define LOLNO 0
# define GIMME_SIZE -1

# define DISP 1

# define FAILMALLOC -2

# define PUSHSWAP 2

typedef struct s_push	t_push;
typedef	struct s_cmd	t_cmd;
typedef struct s_disp	t_disp;

int			ps_init(int ac, char **av, t_push **params, int mode);
int			ps_check_error(int ac, char **av, t_push **params);

int			action_sa(t_push *params);
int			action_sb(t_push *params);
int			action_ss(t_push *params);
int			action_pa(t_push *params);
int			action_pb(t_push *params);
int			action_ra(t_push *params);
int			action_rb(t_push *params);
int			action_rr(t_push *params);
int			action_rra(t_push *params);
int			action_rrb(t_push *params);
int			action_rrr(t_push *params);
void		ps_display_stacks(t_push *params);
void		destroy_pushswap(t_push **params);

void		add_actions(int action, char *s, int len);

#endif
