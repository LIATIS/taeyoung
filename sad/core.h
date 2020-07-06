/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 23:51:35 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:53:31 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

typedef struct	s_dp
{
	int i;
	int j;
}				t_dp;

int		compare(int a, int b, int c);
t_map_square set_result(int size, int x, int y, t_map_square *result);
int set_map_first_line(t_map_con con, t_map_square *result, int *dp_tt);
int set_dp(int i, int j, int dp, t_map_con con);
t_map_square find_square(t_map_con con, int *dp_tt);

#endif