/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:52:48 by snassour          #+#    #+#             */
/*   Updated: 2018/08/30 14:52:52 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <libpushswap.h>
# include <libft.h>

# define CHECKER_ERR -1
# define CHECKER_OK 1
# define CHECKER_KO 0

int		checker_tab_sorted(t_push **params);
int		check_command(char *l, t_cmd toto[NB_ACT + 1]);

#endif
