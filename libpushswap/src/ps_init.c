/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:01:13 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:01:13 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

int		ps_init(int ac, char **av, t_push **params, int mode)
{
	(*params) = NULL;
	(*params) = (t_push *)malloc(sizeof(t_push));
	if (!*params)
		return (ERROR);
	(*params)->index = NULL;
	(*params)->sorted_array = NULL;
	(*params)->taba = NULL;
	(*params)->tabb = NULL;
	(*params)->col = 0;
	(*params)->mode = mode;
	(*params)->opt = (ac >= 2 && (ft_strcmp(av[1], "-v") == 0)) ? DISP : 0;
	(*params)->st_a = 0;
	(*params)->st_b = 0;
	(*params)->max_size = 0;
	if (ps_check_error(ac, av, params) == ERROR)
		return (ERROR);
	(*params)->tabb = (int *)malloc(sizeof(int) * (*params)->max_size);
	if ((*params)->max_size == 0 || !(*params)->tabb)
	{
		ft_memdel((void **)&((*params)->taba));
		return (ERROR);
	}
	(*params)->st_b = (*params)->max_size;
	return (TRUE);
}
