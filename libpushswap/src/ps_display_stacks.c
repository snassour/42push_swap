/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_display_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:03:52 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:03:59 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

void	ps_display_stacks(t_push *params)
{
	size_t i;
	size_t j;

	i = params->st_a;
	j = params->st_b;
	ft_putstr("stack a =");
	while (i < params->max_size)
	{
		ft_putchar(' ');
		ft_putnbr(params->taba[i]);
		++i;
	}
	ft_putendl("");
	ft_putstr("stack b =");
	while (j < params->max_size)
	{
		ft_putchar(' ');
		ft_putnbr(params->tabb[j]);
		++j;
	}
	ft_putendl("");
}
