/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 05:59:44 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 06:07:06 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	checker_free_all(t_push **params, char **line, int mode)
{
	if (read(0, NULL, 0) == 0 || mode == -1)
		close(0);
	if (ft_strcmp(*line, "") != 0)
		get_next_line(0, line);
	ft_memdel((void **)&((*params))->taba);
	ft_memdel((void **)&((*params))->tabb);
	ft_strdel(line);
	return ((*params)->st_a != 0 && mode != -1 ? 0 : mode);
}

static void	checker_init_tab(t_cmd tab_action[NB_ACT + 1])
{
	tab_action[0].key = "sa";
	tab_action[1].key = "sb";
	tab_action[2].key = "ss";
	tab_action[3].key = "pa";
	tab_action[4].key = "pb";
	tab_action[5].key = "ra";
	tab_action[6].key = "rb";
	tab_action[7].key = "rr";
	tab_action[8].key = "rra";
	tab_action[9].key = "rrb";
	tab_action[10].key = "rrr";
	tab_action[11].key = NULL;
	tab_action[0].function = action_sa;
	tab_action[1].function = action_sb;
	tab_action[2].function = action_ss;
	tab_action[3].function = action_pa;
	tab_action[4].function = action_pb;
	tab_action[5].function = action_ra;
	tab_action[6].function = action_rb;
	tab_action[7].function = action_rr;
	tab_action[8].function = action_rra;
	tab_action[9].function = action_rrb;
	tab_action[10].function = action_rrr;
	tab_action[11].function = NULL;
}

int			checker_tab_sorted(t_push **params)
{
	int			command;
	char		*line;
	int			i;
	size_t		tmp;
	t_cmd		tab_action[NB_ACT + 1];

	line = NULL;
	checker_init_tab(tab_action);
	while (get_next_line(0, &line) == 1)
	{
		if ((command = check_command(line, tab_action)) == ERROR)
			return (checker_free_all(params, &line, ERROR));
		ft_strdel(&line);
		tab_action[command].function(*params);
		(*params)->opt == DISP ? ps_display_stacks(*params) : NULL;
	}
	tmp = (*params)->st_a + 1;
	while (tmp < (*params)->max_size && (*params)->max_size > 1)
	{
		if ((*params)->taba[tmp - 1] > (*params)->taba[tmp])
			break ;
		++tmp;
	}
	i = checker_free_all(params, &line, (tmp == (*params)->max_size ? 1 : 0));
	return (i);
}
