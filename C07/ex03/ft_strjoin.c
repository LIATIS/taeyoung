/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:55:47 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/17 16:16:12 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_all_size(int size, char **strs, char *sep)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	i = -1;
	while (sep[++i])
		len += size - 1;
	if (len < 0)
		return (0);
	return (len);
}

void	make_char(char *result, int *i, char *src)
{
	int j;

	j = 0;
	while (src[j])
	{
		result[*i] = src[j];
		(*i)++;
		j++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len;
	int		i;
	int		j;

	len = check_all_size(size, strs, sep);
	printf("%d", len);
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	j = 1;
	make_char(result, &i, strs[0]);
	while (j < size)
	{
		make_char(result, &i, sep);
		make_char(result, &i, strs[j]);
		j++;
	}
	result[len] = 0;
	return (result);
}
