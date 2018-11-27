/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:13:11 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:13:12 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_ra(t_push *params)
{
	size_t	i;
	int		tmp;

	if (params->st_a >= params->max_size - 1)
		return (LOLNO);
	i = params->st_a;
	tmp = params->taba[i];
	while (i < params->max_size - 1)
	{
		params->taba[i] = params->taba[i + 1];
		++i;
	}
	params->taba[i] = tmp;
	if (params->mode == PUSHSWAP)
		add_actions(RA, "ra\n", 3);
	return (OKI);
}
