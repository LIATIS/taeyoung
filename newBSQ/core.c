/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:49:33 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 06:41:14 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"


int 	parse_stdin(void)
{
	t_map		map;
	t_dynamic	dp;
	t_fd		fd;

	if (!(fd.buffer = read_stdin(fd.fd)))
		return (0);
	if (!(readmap_valid_check(&map, &fd)))
		return (0);	
	if (make_map_info(&map, &fd))
		return (0);
	if (memory_malloc_dp(&dp, map.info.scale_x))
		return (0);
	if (!bsq(&dp, &map))
		return (0);
	fill(&dp, &map);
	print_map(map.info.map);
	memory_free_map(&map, &dp);
		return (1);
}

int		parse_file(char *argv)
{
	t_map		map;
	t_dynamic	dp;
	t_fd		fd;

	if(!(fd.fd = open_file(argv)))
		return (0);
	fd.buffer = read_file(fd.fd);
	if (!(readmap_valid_check(&map, &fd)))
		return (0);
	if (make_map_info(&map, &fd))
		return (0);
	if (memory_malloc_dp(&dp, map.info.scale_x));
		return (0);
	if (!bsq(&dp, &map))
		return (0);
	fill(&dp, &map);
	print_map(map.info.map);
	memory_free_map(&map, &dp);
	return (1);
}