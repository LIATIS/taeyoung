/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 06:23:26 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 06:39:08 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int cnt_enter(char *file)
{
	int cnt;

	cnt = 0;
	while (*file)
	{
		if (*file == '\n')
			cnt++;
		file++;
	}
	return (cnt - 1);
}

int pass_firstline(char *file)
{
	int pos;

	pos = 0;
	while (file[pos] != '\0')
	{
		pos++;
		if (file[pos] == '\n')
			break;
	}
	return (pos);
}

int	memory_make_map(t_map *map, int pos, t_fd *fd)
{
	int i;
	int j;
	int len;

	map->info.map = (char **)malloc(sizeof(char *) * (map->info.scale_y + 1));
	if (!map->info.map)
		return (0);
	i = 0;
	while(i < map->info.scale_x)
	{
		(map->info.map)[i] = (char *)malloc(sizeof(char ) * (map->info.scale_x + 1));
		if (!(map->info.map)[i])
			return (0);
		len = 0;
		while (fd->buffer[pos + len] != '\n')
			len++;
		map->info.map[i] = (char *)malloc(sizeof(char) * (len + 1));
		j = 0;
		while (j < len)
		{
			map->info.map[i][j] = fd->buffer[pos + j];
			j++;
		}
	  	(map->info.map)[i][map->info.scale_x] = '\0';
		pos += (len + 1);
		i++;
	}
	(map->info.map)[map->info.scale_y] = '\0';
}

int		readmap_valid_check(t_map *map, t_fd *fd)// 조건 다음줄에서 개행이 나올때까지의 길이를 y_scale로 반환
{
	int	len;
	int	num;

	len = 0;
	while (fd->buffer[len])
		len++;
	if (len < 4)
		return (0);
	map->fill = fd->buffer[--len];
	map->obstacle = fd->buffer[--len];
	map->space = fd->buffer[--len];
	num = ft_atoi(fd->buffer);
	if (num != len + 3)
		return (0);
	map->info.scale_y = len + 3;
	return (1);
}

int	make_map_info(t_map *map, t_fd *fd) //맵의 첫줄에서 x_scale을 반환해서 맵도 만들고  cnt_enter(fd.buffer)
{
	int i;
	int cnt;
	int start_point;

	start_point = pass_firstline(fd->buffer);
	i = 1;
	cnt = 0;///
	while (fd->buffer[start_point + i] != '\n')
		i++;
	map->info.scale_x = i - 1;
	if ((map->info.scale_y) != cnt)
		return (0);
	if (memory_make_map(&map, start_point + 1,  &fd))
		return (0);
	return (1);
}
