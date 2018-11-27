/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:58:09 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 14:58:11 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_sa(t_push *params)
{
	int		tmp;
	size_t	i;

	i = params->st_a;
	if (params->st_a < params->max_size - 1)
	{
		tmp = params->taba[i];
		params->taba[i] = params->taba[i + 1];
		params->taba[i + 1] = tmp;
		if (params->mode == PUSHSWAP)
			add_actions(SA, "sa\n", 3);
		return (OKI);
	}
	return (LOLNO);
}
