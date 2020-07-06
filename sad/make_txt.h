/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_txt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 21:56:37 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:32:09 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_TXT_H
# define MAKE_TXT_H

int		open_file(char *argv);
char	*realloc_buf(char *buf, int buf_size);
char	*ft_make_file(char *file, int file_size, char *buf, int read_size);
char	*read_stdin(void);
char	*read_file(int fd);

#endif