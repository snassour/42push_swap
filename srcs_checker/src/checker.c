/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 05:59:55 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 05:59:56 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int	main(int argc, char **argv)
{
	int		i;
	t_push	**params;

	if (argc == 1)
		return (0);
	if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
		return (0);
	params = NULL;
	params = (t_push **)malloc(sizeof(t_push *));
	if (!params)
		ft_putendl_fd("Error : malloc in program", 2);
	i = 0;
	if ((i = ps_init(argc, argv, params, 0)) == -1)
		ft_putendl_fd("Error", 2);
	else if ((i = checker_tab_sorted(params)) == 1)
		ft_putendl_fd("OK", 1);
	else if (i == 0)
		ft_putendl_fd("KO", 1);
	else if (i == -1)
		ft_putendl_fd("Error", 2);
	destroy_pushswap(params);
	return (0);
}
