/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:12:26 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/10 21:20:05 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int					chk_front_char(char *str, int *i)
{
	int			plus;

	plus = 1;
	while (*(str + *i) < 48 || *(str + *i) > 57)
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

unsigned int		chk_back_int(char *str, int *i)
{
	unsigned int number;

	number = 0;
	while (*(str + *i) >= 48 && *(str + *i) <= 57)
	{
		number = number * 10 + *(str + *i) - 48;
		(*i)++;
	}
	return (number);
}

int					ft_atoi(char *str)
{
	int				i;
	int				result;
	unsigned int	temp;

	i = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	result = chk_front_char(str, &i);
	temp = chk_back_int(str, &i);
	result = temp * result;
	return (result);
}
