/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:57:52 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 14:57:53 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_pb(t_push *params)
{
	if (params->st_b > 0 && params->st_b <= params->max_size)
	{
		params->st_b--;
		params->tabb[params->st_b] = params->taba[params->st_a];
		params->st_a++;
		if (params->mode == PUSHSWAP)
			add_actions(PB, "pb\n", 3);
		return (OKI);
	}
	return (LOLNO);
}
