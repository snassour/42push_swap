/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s_endinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:01:45 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:02:49 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

void	destroy_pushswap(t_push **params)
{
	if (params)
	{
		if (*params)
		{
			if ((*params)->taba)
				ft_memdel((void **)&((*params)->taba));
			if ((*params)->tabb)
				ft_memdel((void **)&((*params)->tabb));
			if ((*params)->index)
				ft_memdel((void **)&((*params)->index));
			if ((*params)->sorted_array)
				ft_memdel((void **)&((*params)->sorted_array));
			ft_memdel((void **)&(*params));
		}
		ft_memdel((void **)&(params));
	}
}
