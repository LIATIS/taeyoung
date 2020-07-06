/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 18:23:28 by hyuyoo            #+#    #+#             */
/*   Updated: 2020/06/18 05:42:12 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <unistd.h>

void	fill(t_dynamic *dp, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < dp->square.size)
	{
		x = 0;
		while(x < dp->square.size)
		{
			map->info.map[dp->square.y - y][dp->square.x - x] = map->fill;
			x++;
		}
		y++;
	}
}

void    print_map(t_map *map)
{
    int y;

    y = 0;
    while (y < map->info.scale_y)
    {
        write(1, map->info.map[y], map->info.scale_x);
        write(1, "\n", 1);
        y++;
    }
    write(1, "\n", 1);
}

void	print_error()
{
	write(1, "map error", 10);
}