/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:12:26 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/29 19:48:05 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*g_str;
char	*g_charset;
char	**g_split_char;
int		g_size;

int		chk_charset(char str)
{
	int i;

	i = 0;
	while (g_charset[i])
	{
		if (str == g_charset[i])
			return (0);
		i++;
	}
	return (1);
}

void	molloc_charset_count(void)
{
	int i;
	int chk;

	i = 0;
	g_size = 0;
	chk = 0;
	while (g_str[i])
	{
		if (chk_charset(g_str[i]) && chk == 0)
		{
			g_size += 1;
			chk = 1;
		}
		else if (!chk_charset(g_str[i]))
			chk = 0;
		i++;
	}
	g_split_char = (char **)malloc(sizeof(char *) * (g_size + 1));
	g_split_char[g_size] = 0;
	if (g_split_char == 0)
		return ;
}

int		assign_split_char(int i, int k)
{
	int a;
	int b;

	a = 0;
	while (chk_charset(g_str[i + a]) && g_str[i + a] != '\0')
		a++;
	g_split_char[k] = (char*)malloc(sizeof(char) * (a + 1));
	g_split_char[k][a] = 0;
	b = 0;
	while (b < a)
	{
		g_split_char[k][b] = g_str[i + b];
		b++;
	}
	return (a - 1);
}

void	split_char(void)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (g_str[i] && k < g_size)
	{
		if (chk_charset(g_str[i]))
		{
			i += assign_split_char(i, k);
			k += 1;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	g_str = str;
	g_charset = charset;
	molloc_charset_count();
	split_char();
	return (g_split_char);
}
