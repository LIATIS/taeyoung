/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 20:39:57 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:33:21 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H

typedef struct	s_map_info
{
	int		x;
	int		y;
	char	**map;
}				t_map_info;

typedef struct	s_map_con
{
	char *firstline;
	char space;
	char obstacle;
	char fill;
	t_map_info map;
}				t_map_con;

typedef struct	s_map_square
{
	int size;
	int x;
	int y;
}				t_map_square;

#endif
