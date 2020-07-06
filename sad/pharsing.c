/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pharsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 21:12:19 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:32:07 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map_info.h"
#include "pharsing.h"
#include "ft_str.h"

void		putin_firstline(char *file, t_map_con *con)
{
	int idx;

	idx = 0;
	while (file[idx] != '\n')
		idx++;
	con->firstline = (char *)malloc(sizeof(char *) * (idx + 1));
	con->firstline[0] = '\0';
	ft_strncat(con->firstline, file, idx);
}

int			cnt_enter(char *file)
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

int			pass_firstline(char *file)
{
	int pos;

	pos = 0;
	while (file[pos] != '\0')
	{
		pos++;
		if (file[pos] == '\n')
			break ;
	}
	return (pos);
}

t_map_info	make_map_info(char *file, int cnt)
{
	int			i;
	int			st;
	t_map_info	info;

	st = pass_firstline(file);
	i = 1;
	while (file[st + i] != '\n')
		i++;
	info.x = i - 1;
	info.y = cnt_enter(file);
	info.map = make_map(info.y, st + 1, file);
	return (info);
}

char		**make_map(int y, int pos, char *file)
{
	int		i;
	int		len;
	int		j;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (y + 1));
	i = 0;
	while (i < y)
	{
		len = 0;
		while (file[pos + len] != '\n')
			len++;
		map[i] = (char *)malloc(sizeof(char) * (len + 1));
		j = 0;
		while (j < len)
		{
			map[i][j] = file[pos + j];
			j++;
		}
		map[i][j] = '\0';
		pos += (len + 1);
		i++;
	}
	return (map);
}
