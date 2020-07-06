/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pharsing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 21:12:19 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:32:06 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHARSING_H
# define PHARSING_H

void		putin_firstline(char *file, t_map_con *con);
int			cnt_enter(char *file);
int			pass_firstline(char *file);
t_map_info	make_map_info(char *file, int cnt);
char		**make_map(int y, int pos, char *file);

#endif
