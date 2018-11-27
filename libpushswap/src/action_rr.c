/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:12:55 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:12:57 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_rr(t_push *params)
{
	int	tmp1;
	int	tmp2;

	tmp1 = action_ra(params);
	tmp2 = action_rb(params);
	if (tmp1 == LOLNO && tmp2 == LOLNO)
		return (LOLNO);
	if (params->mode == PUSHSWAP && tmp1 != LOLNO && tmp2 == LOLNO)
		add_actions(RA, "ra\n", 3);
	else if (params->mode == PUSHSWAP && tmp1 == LOLNO && tmp2 != LOLNO)
		add_actions(RB, "rb\n", 3);
	else if (params->mode == PUSHSWAP)
		add_actions(RR, "rr\n", 3);
	return (OKI);
}
