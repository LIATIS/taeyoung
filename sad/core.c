/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:56:48 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:55:59 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "core.h"
#include "map_info.h"
#include "ft_str.h"

t_map_square	set_result(int size, int x, int y, t_map_square *result)
{
	if (size > (*result).size)
	{
		(*result).size = size;
		(*result).x = x;
		(*result).y = y;
	}
	return (*result);
}

int				set_map_first_line(t_map_con con,
				t_map_square *result, int *dp_tt)
{
	int	j;

	(*result).size = 0;
	(*result).x = 0;
	(*result).y = 0;
	j = -1;
	while (++j < con.map.x)
	{
		if (con.map.map[0][j] == con.space)
			dp_tt[j] = 1;
		else if (con.map.map[0][j] == con.obstacle)
			dp_tt[j] = 0;
		else
			return (1);
		*result = set_result(dp_tt[j], j, 0, result);
	}
	return (0);
}

int				set_dp(t_dp dpdp, int dp, t_map_con con, int *dp_tt)
{
	if (con.map.map[dpdp.i][dpdp.j] == con.space && dpdp.j == 0)
		return (1);
	else if (con.map.map[dpdp.i][dpdp.j] == con.space)
		return (compare(dp_tt[dpdp.j], dp, dp_tt[dpdp.j - 1]));
	else if (con.map.map[dpdp.i][dpdp.j] == con.obstacle)
		return (0);
	else 
		return (-1);
}

t_map_square 	return_error_bysize(int message, t_map_square result)
{
	result.size = message;
	result.x = 0;
	result.y = 0;
	return (result);
}

t_map_square	find_square(t_map_con con, int *dp_tt)
{
	t_dp			dpdp;
	int				dp[2];
	t_map_square	result;

	if (set_map_first_line(con, &result, dp_tt))
		return (return_error_bysize(-1, result));
	dpdp.i = 0;
	while (++dpdp.i < con.map.y && con.map.y > 1)
	{
		dpdp.j = -1;
		dp[0] = 0;
		while (++dpdp.j < con.map.x)
		{
			if ((dp[1] = set_dp(dpdp, dp[0], con, dp_tt)) == -1)
				return (return_error_bysize(-1, result));
			dp_tt[dpdp.j - 1] = dp[0];
			dp[0] = dp[1];
			if (dpdp.j == con.map.x - 1)
				dp_tt[dpdp.j] = dp[1];
			result = set_result(dp[1], dpdp.j, dpdp.i, &result);
		}
	}
	return (result);
}
