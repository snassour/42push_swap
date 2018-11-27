/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:58:43 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 14:58:44 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_ss(t_push *params)
{
	int	tmp1;
	int	tmp2;

	tmp1 = action_sa(params);
	tmp2 = action_sb(params);
	if (tmp1 == LOLNO && tmp2 == LOLNO)
		return (LOLNO);
	if (params->mode == PUSHSWAP && tmp1 != LOLNO && tmp2 == LOLNO)
		add_actions(SA, "sa\n", 3);
	else if (params->mode == PUSHSWAP && tmp1 == LOLNO && tmp2 != LOLNO)
		add_actions(SB, "sb\n", 3);
	else if (params->mode == PUSHSWAP)
		add_actions(SS, "ss\n", 3);
	return (OKI);
}
