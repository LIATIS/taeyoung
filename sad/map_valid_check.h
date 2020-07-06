/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_check.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 20:51:09 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:31:56 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALID_CHECK_H
# define MAP_VALID_CHECK_H

int		ft_atoi(char *str);
int		check_char(char c);
int		check_line(char *line, int col, char obs, char empty);
int		check_matrix(t_map_info *map_info, char obs, char empty);
int		map_valid_check(t_map_con *map_con);

#endif
