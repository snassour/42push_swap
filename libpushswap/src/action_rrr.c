/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:13:17 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:13:18 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_rrr(t_push *params)
{
	int tmp1;
	int	tmp2;

	tmp1 = action_rra(params);
	tmp2 = action_rrb(params);
	if (tmp1 == LOLNO && tmp2 == LOLNO)
		return (LOLNO);
	if (params->mode == PUSHSWAP && tmp1 != LOLNO && tmp2 == LOLNO)
		add_actions(RRA, "rra\n", 4);
	else if (params->mode == PUSHSWAP && tmp1 == LOLNO && tmp2 != LOLNO)
		add_actions(RRB, "rrb\n", 4);
	else if (params->mode == PUSHSWAP)
		add_actions(RRR, "rrr\n", 4);
	return (OKI);
}
