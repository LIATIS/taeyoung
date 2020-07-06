/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 03:21:55 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 06:35:26 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

int 	memory_malloc_dp(t_dynamic *dp, int xscale)
{
	dp->dp_table = (int *) malloc(sizeof(int) * (xscale + 1));
	if (!dp->dp_table)
		return (0);
	(dp->dp_table)[xscale] = '\0';
	return (1);
}

void	memory_free_map(t_map *map, t_dynamic *dp)
{
	int i;

	i = 0;
	while (map->info.map[i])
	{
		free(map->info.map[i]);
		i++;
	}
	free(map->info.map);
	free(dp->dp_table);
}