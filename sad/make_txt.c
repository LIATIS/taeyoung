/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 22:02:52 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 07:32:16 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "map_info.h"
#include "ft_str.h"

int		open_file(char *argv)
{
	int fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}

char	*realloc_buf(char *buf, int buf_size)
{
	free(buf);
	if ((buf = (char*)malloc(sizeof(char) * buf_size)) == NULL)
		return (NULL);
	return (buf);
}

char	*ft_make_file(char *file, char *buf, int file_size, int read_size)
{
	char	*temp;

	if (file_size == 0)
	{
		file = (char *)malloc(sizeof(char) * (file_size + 1));
		file[0] = '\0';
	}
	temp = (char *)malloc(sizeof(char) * (file_size + read_size + 1));
	if (temp != 0)
	{
		temp[0] = '\0';
		ft_strcat(temp, file);
		ft_strncat(temp, buf, read_size);
		free(file);
	}
	return (temp);
}

char	*read_stdin(void)
{
	char	*buf;
	char	*file;
	int		file_size;
	int		read_size;
	int		buf_size;

	buf_size = 2;
	file_size = 0;
	file = NULL;
	if ((buf = malloc(sizeof(char) * buf_size)) == NULL)
		return (NULL);
	while ((read_size = read(STDIN_FILENO, buf, buf_size)))
	{
		if (read_size < 0)
			return (NULL);
		if ((file = ft_make_file(file, buf, file_size, read_size)) == NULL)
			return (NULL);
		file_size += read_size;
		buf_size *= 2;
		if ((buf = realloc_buf(buf, buf_size)) == NULL)
			return (NULL);
	}
	free(buf);
	return (file);
}

char	*read_file(int fildes)
{
	char	*buf;
	char	*file;
	int		file_size;
	int		read_size;
	int		buf_size;

	buf_size = 2;
	file_size = 0;
	file = NULL;
	if ((buf = malloc(sizeof(char) * buf_size)) == NULL)
		return (NULL);
	while ((read_size = read(fildes, buf, buf_size)))
	{
		if (read_size < 0)
			return (NULL);
		if ((file = ft_make_file(file, buf, file_size, read_size)) == NULL)
			return (NULL);
		file_size += read_size;
		buf_size *= 2;
		if ((buf = realloc_buf(buf, buf_size)) == NULL)
			return (NULL);
	}
	free(buf);
	return (file);
}
