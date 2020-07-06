/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:12:26 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/14 17:40:46 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			chk_validation(char *base)
{
	int i;
	int j;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-' ||
			(*(base + i) >= 9 && *(base + i) <= 13) || *(base + i) == 32)
			return (1);
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void		chk_back_int(unsigned int num, char *base, int size)
{
	char print;

	if (num >= size)
	{
		chk_back_int(num / size, base, size);
		chk_back_int(num % size, base, size);
	}
	else
	{
		print = *(base + num);
		write(1, &print, 1);
	}
}

void		ft_putnbr_base(int nbr, char *base)
{
	int				size;
	unsigned int	u_num;

	size = 0;
	while (*(base + size))
		size++;
	if (size < 2 || chk_validation(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		u_num = -nbr;
	}
	else
		u_num = nbr;
	chk_back_int(u_num, base, size);
}
