/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:14:03 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:14:04 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_rrb(t_push *params)
{
	size_t	i;
	int		tmp;

	if (params->st_b >= params->max_size - 1)
		return (LOLNO);
	i = params->max_size;
	tmp = params->tabb[i - 1];
	while (--i > params->st_b)
		params->tabb[i] = params->tabb[i - 1];
	params->tabb[i] = tmp;
	if (params->mode == PUSHSWAP)
		add_actions(RRB, "rrb\n", 4);
	return (OKI);
}
