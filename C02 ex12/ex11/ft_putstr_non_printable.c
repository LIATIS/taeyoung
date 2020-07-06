/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:25:08 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/09 15:04:14 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	make_fifteen(char code)
{
	unsigned int	a;
	const char		*hex = "0123456789abcdef";

	a = (unsigned char)code;
	if (a > 16)
		write(1, &hex[a / 16], 1);
	else
		write(1, "0", 1);
	write(1, &hex[a % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) > 126 || *(str + i) < 32)
		{
			write(1, "\\", 1);
			make_fifteen(*(str + i));
		}
		else
		{
			write(1, str + i, 1);
		}
		i++;
	}
}
