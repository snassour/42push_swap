/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 01:51:11 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 05:47:48 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libpushswap.h>
# include <libft.h>

int		main_small_errors(int argc, char **argv);
void	choose_algo(t_push **p);
void	algo_big(t_push **params);
void	new_sort_push_to_a(t_push **p);
void	new_sort_push_to_b(t_push **params);
int		next_med_index(t_push **params);
int		sorted_a(t_push **params);
void	choose_small(t_push **p);
void	push_s_five_algo(t_push **p);
int		next_sorted(int first, int last, int *tab1, int *tab2);
void	push_s_four_algo(t_push **params);
void	push_s_three_algo(t_push **params);
int		sort_array(t_push **p);
void	update_stack(int *stack, int num1, int num2, int *top);
int		copy_array(t_push **params);
int		partition_sort_array(int *tab, int *index, int low, int high);
void	sort_array_swap(int i, int j, int *tab, int *index_tab);

#endif
