/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:12:26 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/10 21:18:34 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int					chk_validation(char *base)
{
	int			i;
	int			j;
	int			size;

	size = 0;
	while (*(base + size))
		size++;
	i = -1;
	while (++i < size)
	{
		if (*(base + i) == '+' || *(base + i) == '-' ||
			(*(base + i) >= 9 && *(base + i) <= 13) || *(base + i) == 32)
			return (0);
		j = i + 1;
		while (j < size)
			if (*(base + i) == *(base + j++))
				return (0);
	}
	return (size);
}

int					chk_base(char *str, char *base)
{
	int i;

	i = 0;
	while (*(base + i))
	{
		if (*str == *(base + i))
			return (i);
		i++;
	}
	return (-100);
}

int					chk_front_char(char *str, int *i, char *base)
{
	int			plus;

	plus = 1;
	while (chk_base((str + *i), base) == -100)
	{
		if (*(str + *i) == '-')
			plus *= -1;
		else if (*(str + *i) == '+')
			plus *= 1;
		else
			return (0);
		(*i)++;
	}
	return (plus);
}

unsigned int		chk_back_int(char *str, int *i, char *base, int size)
{
	unsigned int	number;
	int				nextnumber;

	number = 0;
	nextnumber = chk_base(str + *i, base);
	while (nextnumber != -100)
	{
		number = number * size + nextnumber;
		(*i)++;
		nextnumber = chk_base(str + *i, base);
	}
	return (number);
}

int					ft_atoi_base(char *str, char *base)
{
	int			i;
	int			result;
	int			size;

	size = chk_validation(base);
	if (size < 2)
		return (0);
	i = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	result = chk_front_char(str, &i, base);
	result = result * chk_back_int(str, &i, base, size);
	return (result);
}
