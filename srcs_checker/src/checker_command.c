/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 06:00:03 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 06:06:36 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int		check_command(char *l, t_cmd tab_action[NB_ACT + 1])
{
	size_t	i;
	int		j;

	if (!l || !l[0])
		return (-1);
	i = ft_strlen(l);
	if (i > 3 || i < 2)
		return (-1);
	j = 0;
	while (j < NB_ACT && ft_strcmp(l, tab_action[j].key))
		++j;
	if (j == NB_ACT)
		return (-1);
	return (j);
}
