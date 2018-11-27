/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:55:22 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 14:55:23 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRUCT_H
# define PS_STRUCT_H
# include <libpushswap.h>

typedef struct s_push	t_push;
typedef int	(*t_pushswap)(t_push *params);

struct	s_cmd
{
	t_pushswap	function;
	char		*key;
};

struct	s_push
{
	int				mode;
	int				*taba;
	int				*tabb;
	size_t			st_a;
	size_t			st_b;
	size_t			max_size;
	int				opt;
	int				col;
	int				*sorted_array;
	int				*index;
};

#endif
