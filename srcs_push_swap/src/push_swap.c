/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:13:54 by snassour          #+#    #+#             */
/*   Updated: 2018/08/25 16:58:31 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int argc, char **argv)
{
	int		i;
	t_push	**params;

	if (argc == 1)
		return (0);
	params = NULL;
	if (!(params = (t_push **)malloc(sizeof(t_push *))))
		return (-1 + 0 * write(1, "Error : malloc\n", 15));
	if ((i = ps_init(argc, argv, params, PUSHSWAP)) == ERROR)
		ft_putendl_fd("Error", 2);
	else
	{
		(*params)->mode = PUSHSWAP;
		sort_array(params);
		choose_algo(params);
	}
	destroy_pushswap(params);
	return (0);
}
