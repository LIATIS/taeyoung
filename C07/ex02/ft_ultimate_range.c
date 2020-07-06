/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:55:47 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/15 20:27:29 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		*temp;
	int		size;
	int		i;

	size = max - min;
	if (size <= 0)
		return (0);
	temp = (int *)malloc(sizeof(int) * (size));
	if (!temp)
		return (-1);
	i = 0;
	while (i < size)
	{
		temp[i] = min++;
		i++;
	}
	*range = temp;
	return (size);
}
