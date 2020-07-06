/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:54:53 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 06:33:55 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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
	char *temp;
	
	if (file_size == 0)
	{
		file = (char *)malloc(sizeof(char) * (file_size + 1));
		if (!file)//
			return (0);//
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
	if (!temp)//
		return (0);//
	return (temp);
}

char	*read_stdin(int fd)
{
	char	*buf;
	char	*file;
	int		file_size;
	int		read_size;
	int		buf_size;

	buf_size = 0;
	file_size = 0;
	file = NULL;
	if ((buf = malloc(sizeof(char) * buf_size)) == NULL)
		return (NULL);
	while ((read_size = read(STDIN_FILENO, buf, buf_size)) && file[file_size] != "\n")
	{
		if (read_size < 0)
			return (NULL);
		if ((file = ft_make_file(file, buf, file_size, read_size)) == NULL)
			return (NULL);
		file_size += read_size;
		buf_size += 1;
		if ((buf = realloc_buf(buf, buf_size)) == NULL)
			return (NULL);
	}
	free(buf);
	return (file);
}

