/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:12:26 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/17 13:58:23 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

extern char				*make_pointer_with_size(int *to_char_size, int plus);
extern unsigned int		size_of_basechar(unsigned int num, unsigned int size);
extern void				chg_char(unsigned int num,
char *r_c, char *b_t, int s_t);

int g_size_from;
int g_size_to;
int g_i;

int						chk_validation(char *base)
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

int						chk_base(char *str, char *base)
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

int						chk_front_char(char *str, char *base)
{
	int			plus;

	while ((str[g_i] >= 9 && str[g_i] <= 13) || str[g_i] == 32)
		(g_i)++;
	plus = 1;
	while (chk_base((str + g_i), base) == -100)
	{
		if (*(str + g_i) == '-')
			plus *= -1;
		else if (*(str + g_i) == '+')
			plus *= 1;
		else
			return (0);
		g_i++;
	}
	return (plus);
}

unsigned int			chk_back_int(char *str, char *base, int size)
{
	unsigned int	number;
	int				nextnumber;

	number = 0;
	nextnumber = chk_base(str + g_i, base);
	while (nextnumber != -100)
	{
		number = number * size + nextnumber;
		g_i++;
		nextnumber = chk_base(str + g_i, base);
	}
	return (number);
}

char					*ft_convert_base(char *nbr,
						char *base_from, char *base_to)
{
	unsigned int	result_num;
	int				plus;
	int				to_ch_size;
	char			*result_char;

	g_size_from = chk_validation(base_from);
	g_size_to = chk_validation(base_to);
	if (g_size_from < 2 || g_size_to < 2)
		return (0);
	g_i = 0;
	plus = chk_front_char(nbr, base_from);
	result_num = chk_back_int(nbr, base_from, g_size_from);
	to_ch_size = size_of_basechar(result_num, g_size_to);
	result_char = make_pointer_with_size(&to_ch_size, plus);
	chg_char(result_num, result_char + to_ch_size - 1, base_to, g_size_to);
	return (result_char);
}
