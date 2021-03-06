/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:12:26 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/02 13:13:12 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char a;

	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2", 2);
			ft_putnbr(147483648);
			return ;
		}
		write(1, "-", 1);
		ft_putnbr(nb * -1);
		return ;
	}
	if (nb < 10)
	{
		a = nb + 48;
		write(1, &a, 1);
		return ;
	}
	ft_putnbr(nb / 10);
	a = nb % 10 + 48;
	write(1, &a, 1);
}
