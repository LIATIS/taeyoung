/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 08:43:12 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/07 11:19:56 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_rev_int_tab(int *tab, int size)
{
	int		blank;
	int		i;

	i = 0;
	while (i * 2 < size)
	{
		blank = *(tab + i);
		*(tab + i) = *(tab + size - i - 1);
		*(tab + size - i - 1) = blank;
		i++;
	}
}
