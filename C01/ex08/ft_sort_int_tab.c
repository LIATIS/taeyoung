/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 08:43:12 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/06 21:35:23 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		blank;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (*(tab + j) > *(tab + j + 1))
			{
				blank = *(tab + j);
				*(tab + j) = *(tab + j + 1);
				*(tab + j + 1) = blank;
			}
			j++;
		}
		i++;
	}
}
