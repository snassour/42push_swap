/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_pile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:02:59 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 15:03:35 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpushswap.h>

static int		ps_get_size(char **str)
{
	int l;

	l = 0;
	while (str[l])
		++l;
	return (l);
}

static int		ps_check_doubles(t_push **params, int place)
{
	int		num;
	int		i;
	int		last;

	last = place;
	if (last == 0)
		return (1);
	num = (*params)->taba[last];
	i = 0;
	while ((*params)->taba[i] != num)
		++i;
	return (i == last ? 1 : 0);
}

static int		ps_tstrtoti(t_push **params, char **s)
{
	int	i;

	i = 0;
	while (ft_isint(s[i]) && (*params)->taba)
	{
		(*params)->taba[i] = ft_atoi(s[i]);
		if (ps_check_doubles(params, i) == 0)
			break ;
		++i;
	}
	return (i);
}

int				ps_check_error(int ac, char **av, t_push **params)
{
	int		i;
	char	**s;
	int		len;
	int		l;

	i = 0;
	s = NULL;
	(*params)->taba = NULL;
	(*params)->tabb = NULL;
	len = 0;
	l = (((*params)->opt == DISP && (*params)->mode != PUSHSWAP) ? 2 : 1);
	i = 0;
	if (!(s = ((ac == 3 && l == 2) || (ac == 2 && l == 1) ?
		ft_splitwhitespaces(av[l]) : &av[l])))
		return (ERROR);
	len = ps_get_size(s);
	(*params)->taba = (int *)malloc(sizeof(int) * len);
	i = ps_tstrtoti(params, s);
	if ((ac == 3 && l == 2) || (ac == 2 && l == 1))
		ft_tabstrdel(&s, len);
	(*params)->max_size = (i != len ? 0 : len);
	i != len ? ft_memdel((void **)&((*params)->taba)) : NULL;
	return ((*params)->taba == NULL || len == 0 ? ERROR : TRUE);
}
