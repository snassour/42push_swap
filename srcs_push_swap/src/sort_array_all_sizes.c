/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array_all_sizes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 00:13:50 by snassour          #+#    #+#             */
/*   Updated: 2018/08/27 00:13:58 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_array_swap(int i, int j, int *tab, int *index_tab)
{
	int tmp;

	if (i < j && tab[i] < tab[j])
		return ;
	if (i > j && tab[i] > tab[j])
		return ;
	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
	tmp = index_tab[i];
	index_tab[i] = index_tab[j];
	index_tab[j] = tmp;
}

int		partition_sort_array(int *tab, int *index, int low, int high)
{
	int		pivot;
	int		first_element;
	int		i;

	pivot = tab[high];
	first_element = low - 1;
	i = low;
	while (i <= high - 1)
	{
		if (tab[i] <= pivot)
		{
			first_element++;
			if (first_element != i)
				sort_array_swap(first_element, i, tab, index);
		}
		++i;
	}
	sort_array_swap(first_element + 1, high, tab, index);
	return (first_element + 1);
}

int		copy_array(t_push **params)
{
	int		top;
	int		low;
	int		high;

	top = -1;
	low = 0;
	high = (int)(*params)->max_size - 1;
	(*params)->sorted_array = (int *)malloc((*params)->max_size * sizeof(int));
	(*params)->index = (int *)malloc((*params)->max_size * sizeof(int));
	if (!(*params)->sorted_array || !(*params)->index)
		return (-1);
	while (++top <= high)
	{
		(*params)->index[top] = top;
		(*params)->sorted_array[top] = (*params)->taba[top];
	}
	return (1);
}

void	update_stack(int *stack, int num1, int num2, int *top)
{
	stack[++(*top)] = num1;
	stack[++(*top)] = num2;
}

int		sort_array(t_push **p)
{
	int	top;
	int	par;
	int	stack[(*p)->max_size];
	int	high;
	int	low;

	if (copy_array(p) == -1)
		return (0);
	top = -1;
	low = 0;
	high = (int)(*p)->max_size - 1;
	stack[++top] = low;
	stack[++top] = high;
	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];
		par = partition_sort_array((*p)->sorted_array, (*p)->index, low, high);
		if (par - 1 > low)
			update_stack(stack, low, par - 1, &top);
		if (par + 1 < high)
			update_stack(stack, par + 1, high, &top);
	}
	return (1);
}
