/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:13:21 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:13:23 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_rra(t_push *params)
{
	size_t	i;
	int		tmp;

	if (params->st_a >= params->max_size - 1)
		return (LOLNO);
	i = params->max_size;
	tmp = params->taba[i - 1];
	while (--i > params->st_a)
		params->taba[i] = params->taba[i - 1];
	params->taba[i] = tmp;
	if (params->mode == PUSHSWAP)
		add_actions(RRA, "rra\n", 4);
	return (OKI);
}
