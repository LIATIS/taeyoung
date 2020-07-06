/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 21:04:43 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:27:10 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

int     ft_strlen(char *str);
char    *ft_strncpy(char *dest, char *src, unsigned int n);
void    ft_strcat(char *desti, char *src);
void    ft_strncat(char *desti, char *src, int read_size);
int		compare(int a, int b, int c);

#endif