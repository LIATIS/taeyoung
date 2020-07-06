/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:55:47 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/15 20:27:45 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*arr;
	int		size;
	int		i;

	size = 0;
	while (*(src + size))
		size++;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		*(arr + i) = *(src + i);
		i++;
	}
	arr[size] = 0;
	return (arr);
}
