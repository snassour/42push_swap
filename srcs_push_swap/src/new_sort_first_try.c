/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort_first_try.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 05:48:19 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 05:54:01 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		sorted_a(t_push **params)
{
	int	i;

	i = (int)(*params)->st_a - 1;
	if ((*params)->st_a == (*params)->max_size - 1)
		return (0);
	while (++i < (int)(*params)->max_size - 1)
		if ((*params)->taba[i] > (*params)->taba[i + 1])
			return (-1);
	return (0);
}

int		next_med_index(t_push **params)
{
	int		size_a;

	size_a = (int)(*params)->max_size - 1 - (int)(*params)->st_a;
	if (size_a > 450)
		return ((size_a / 7) + (int)(*params)->st_a);
	else if (size_a > 200)
		return ((size_a / 8) + (int)(*params)->st_a);
	else if (size_a > 100)
		return ((size_a / 7) + (int)(*params)->st_a);
	else if (size_a > 25)
		return ((size_a / 4) + (int)(*params)->st_a);
	if (size_a <= 10)
		return ((int)(*params)->max_size - 6);
	return ((size_a / 2) + (int)(*params)->st_a);
}

void	new_sort_push_to_b(t_push **params)
{
	int		i;
	int		med;
	int		index_med;

	med = 0;
	index_med = 0;
	while ((int)(*params)->st_a <= (int)(*params)->max_size - 6 \
		&& sorted_a(params) && (*params)->st_a < (*params)->max_size)
	{
		i = (*params)->st_a;
		index_med = next_med_index(params);
		med = (*params)->sorted_array[index_med];
		while (i <= index_med)
		{
			if ((*params)->taba[(*params)->st_a] <= med)
			{
				action_pb(*params);
				++i;
			}
			else
				action_ra(*params);
		}
	}
	if ((int)(*params)->st_a > (int)(*params)->max_size - 6)
		choose_small(params);
}

void	new_sort_push_to_a(t_push **p)
{
	int		next;
	int		i;
	int		middle;

	while ((*p)->st_b <= (*p)->max_size - 1)
	{
		i = (int)(*p)->st_b;
		next = (int)(*p)->max_size - 1 - i;
		middle = (next / 2) + i;
		i = next_sorted(i, next, (*p)->tabb, (*p)->sorted_array);
		while ((*p)->tabb[(*p)->st_b] != (*p)->sorted_array[next])
		{
			if (i > middle)
			{
				action_rrb(*p);
			}
			else if (i <= middle)
				action_rb(*p);
		}
		action_pa(*p);
	}
}

void	algo_big(t_push **params)
{
	new_sort_push_to_b(params);
	new_sort_push_to_a(params);
}
