/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 00:06:50 by snassour          #+#    #+#             */
/*   Updated: 2018/08/27 00:06:54 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_s_three_algo(t_push **params)
{
	int		a;
	int		b;
	int		c;

	a = (*params)->taba[(*params)->st_a];
	b = (*params)->taba[(*params)->st_a + 1];
	c = (*params)->taba[(*params)->st_a + 2];
	if (b > c && a < c && a < b)
	{
		action_rra(*params);
		action_sa(*params);
	}
	if (a > b && b < c && a < c)
		action_sa(*params);
	if (a > b && a > c && b < c)
		action_ra(*params);
	if (c < b && c < a && a < b)
		action_rra(*params);
	if (a > b && b > c)
	{
		action_ra(*params);
		action_sa(*params);
	}
}

void	push_s_four_algo(t_push **p)
{
	while ((*p)->taba[(*p)->st_a] != (*p)->sorted_array[(*p)->st_a])
		if ((*p)->index[(*p)->st_a] != 0 && (*p)->index[(*p)->st_a] != 1)
			action_rra(*p);
		else
			action_ra(*p);
	if (sorted_a(p) == 0)
		return ;
	action_pb(*p);
	push_s_three_algo(p);
	action_pa(*p);
}

int		next_sorted(int first, int last, int *tab1, int *tab2)
{
	while (tab1[first] != tab2[last])
		++(first);
	return (first);
}

void	push_s_five_algo(t_push **p)
{
	int		len;
	int		i;

	len = (int)(*p)->max_size;
	i = next_sorted((*p)->st_a, (*p)->st_a, (*p)->taba, (*p)->sorted_array);
	while ((*p)->taba[(*p)->st_a] != (*p)->sorted_array[(*p)->st_a])
		i > len / 2 ? action_rra(*p) : action_ra(*p);
	action_pb(*p);
	i = next_sorted((*p)->st_a, (*p)->st_a, (*p)->taba, (*p)->sorted_array);
	while ((*p)->taba[(*p)->st_a] != (*p)->sorted_array[(*p)->st_a])
		i > len / 2 ? action_rra(*p) : action_ra(*p);
	if (!sorted_a(p))
	{
		action_pa(*p);
		return ;
	}
	action_pb(*p);
	push_s_three_algo(p);
	if ((*p)->tabb[(*p)->st_b] < (*p)->tabb[(*p)->st_b + 1])
		action_sb(*p);
	action_pa(*p);
	action_pa(*p);
}

void	choose_small(t_push **p)
{
	int	i;

	i = (*p)->max_size - (*p)->st_a;
	if (i == 2
		&& (*p)->taba[(*p)->st_a] > (*p)->taba[(*p)->st_a + 1])
		action_sa(*p);
	if (i == 3)
		push_s_three_algo(p);
	if (i == 4)
		push_s_four_algo(p);
	if (i == 5)
		push_s_five_algo(p);
}
