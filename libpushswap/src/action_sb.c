/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:58:23 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 14:58:24 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_sb(t_push *params)
{
	int		tmp;
	size_t	i;

	i = params->st_b;
	if (params->st_b < params->max_size - 1)
	{
		tmp = params->tabb[i];
		params->tabb[i] = params->tabb[i + 1];
		params->tabb[i + 1] = tmp;
		if (params->mode == PUSHSWAP)
			add_actions(SB, "sb\n", 3);
		return (OKI);
	}
	return (LOLNO);
}
