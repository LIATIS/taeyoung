/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:32:36 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:31:45 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"
#include "ft_str.h"
#include <stdio.h>

int		ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result + str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

int		check_char(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int		check_line(char *line, int col, char obs, char empty)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != obs && line[i] != empty)
			return (0);
		i++;
	}
	if (i != col)
		return (0);
	return (1);
}

int		check_matrix(t_map_info *map_info, char obs, char empty)
{
	int	i;

	i = 0;
	if (map_info->x <= 0)
		return (0);
	while (i < map_info->y)
	{
		if (check_line(map_info->map[i], map_info->x, obs, empty) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		map_valid_check(t_map_con *map_con)
{
	int		len;
	int		num;

	len = ft_strlen(map_con->firstline);
	if (len < 4)
		return (0);
	map_con->fill = map_con->firstline[--len];
	map_con->obstacle = map_con->firstline[--len];
	map_con->space = map_con->firstline[--len];
	map_con->firstline[len] = '\0';
	num = ft_atoi(map_con->firstline);
	if (num <= 0 || num != map_con->map.y)
		return (0);
	if (!(check_char(map_con->fill) && check_char(map_con->obstacle)
				&& check_char(map_con->space)))
		return (0);
	if (map_con->fill == map_con->obstacle || map_con->fill == map_con->space
			|| map_con->obstacle == map_con->space)
		return (0);
	if (check_matrix(&(map_con->map), map_con->obstacle, map_con->space) == 0)
		return (0);
	return (1);
}
