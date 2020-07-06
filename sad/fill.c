/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 18:23:28 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:33:46 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "map_info.h"
#include <unistd.h>

t_map_info		fill(t_map_square square, t_map_con con)
{
	int	i;
	int	j;

	i = 0;
	while (i < square.size)
	{
		j = 0;
		while(j < square.size)
		{
			con.map.map[square.y - i][square.x - j] = con.fill;
			j++;
		}
		i++;
	}
	return (con.map);
}

void			print_map(t_map_con con)
{
	int i;

	i = 0;
	while (i < con.map.y)
	{
		write(1, con.map.map[i], con.map.x);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}