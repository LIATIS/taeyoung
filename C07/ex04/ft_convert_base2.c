/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:55:47 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/17 13:53:38 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char				*make_pointer_with_size(int *to_char_size, int plus)
{
	char *result_char;

	if (plus < 0)
		*to_char_size += 1;
	result_char = (char*)malloc(sizeof(char) * (*to_char_size + 1));
	if (plus < 0)
		*result_char = '-';
	result_char[*to_char_size] = 0;
	return (result_char);
}

unsigned int		size_of_basechar(unsigned int num, unsigned int size)
{
	if (num >= size)
		return (1 + size_of_basechar(num / size, size));
	else
		return (1);
}

void				chg_char(unsigned int num, char *r_c, char *b_t, int s_t)
{
	if (num >= (unsigned int)s_t)
	{
		chg_char(num % s_t, r_c, b_t, s_t);
		chg_char(num / s_t, r_c - 1, b_t, s_t);
	}
	else
	{
		*r_c = *(b_t + num);
	}
}
