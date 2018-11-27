/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 01:45:01 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 01:45:05 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	choose_algo(t_push **p)
{
	if (!sorted_a(p))
		return ;
	if ((*p)->max_size < 6)
		choose_small(p);
	else
		algo_big(p);
}
