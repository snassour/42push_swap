/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:57:34 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 14:57:37 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_pa(t_push *params)
{
	if (params->st_a > 0 && params->st_a <= params->max_size)
	{
		params->st_a--;
		params->taba[params->st_a] = params->tabb[params->st_b];
		params->st_b++;
		if (params->mode == PUSHSWAP)
			add_actions(PA, "pa\n", 3);
		return (OKI);
	}
	return (LOLNO);
}
