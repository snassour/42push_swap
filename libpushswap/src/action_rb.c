/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:13:05 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:13:06 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		action_rb(t_push *params)
{
	size_t	i;
	int		tmp;

	if (params->st_b >= params->max_size - 1)
		return (LOLNO);
	i = params->st_b;
	tmp = params->tabb[i];
	while (i < params->max_size - 1)
	{
		params->tabb[i] = params->tabb[i + 1];
		++i;
	}
	params->tabb[i] = tmp;
	if (params->mode == PUSHSWAP)
		add_actions(RB, "rb\n", 3);
	return (OKI);
}
