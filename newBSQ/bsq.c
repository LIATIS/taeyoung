/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 03:51:04 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 06:30:05 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

int		ft_compare(int a, int b, int c)
{
	a = a < b ? a : b;
	return (a < c ? a + 1 : c + 1);
}

void 	set_result(int size, int x, int y, t_dynamic *dp)
{
	if (size > dp->square.size)
	{
		dp->square.size = size;
		dp->square.x = x;
		dp->square.y = y;
	}
}

int 	set_dp_table_first_line(t_map *map, t_dynamic *dp)
{
	int	x;

	dp->square.size = -1;
	set_result(0, 0, 0, dp);
	x = -1;
	while (++x < map->info.scale_x)
	{
		if (map->info.map[0][x] == map->space)
			dp->dp_table[x] = 1;
		else if (map->info.map[0][x] == map->obstacle)
			dp->dp_table[x] = 0;
		else
			return (1);
		set_result(dp->dp_table[x], x, 0, dp);
	}
	return (0);
}

int 	set_dp(t_dynamic *dp, t_map *map)
{
	if (map->info.map[dp->y][dp->x] == map->space && dp->x == 0)
		return (1);
	else if (map->info.map[dp->y][dp->x] == map->space)
		return (ft_compare(dp->dp_table[dp->x], dp->dp[0], dp->dp_table[dp->x - 1]));
	else if (map->info.map[dp->y][dp->x] == map->obstacle)
		return (0);
	else 
		return (-1);
}

int		bsq(t_dynamic *dp, t_map *map)
{
	if (set_dp_table_first_line(map, dp))
		return (0);
	dp->y = -1;
	while (++(dp->y) < map->info.scale_y && map->info.scale_y > 1)
	{
		dp->x = -1;
		dp->dp[0] = 0;
		while (++(dp->x) < map->info.scale_x)
		{
			if ((dp->dp[1] = set_dp(dp, map)) == -1)
				return (0);
			dp->dp_table[dp->x - 1] = dp->dp[0];
			dp->dp[0] = dp->dp[1];
			if (dp->x == map->info.scale_x - 1)
				dp->dp_table[dp->x] = dp->dp[1];
			set_result(dp->dp[1], dp->x, dp->y, dp);
		}
		if (map->info.map[dp->y][map->info.scale_x] != '\0')
			return (0);
	}
	return (1);
}
