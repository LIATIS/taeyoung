/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:25:08 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/07 11:25:23 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		size;
	int		to_find_count;

	if (*(to_find) == '\0')
		return (str);
	size = ft_strlen(to_find);
	i = 0;
	to_find_count = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) != *(to_find + to_find_count))
		{
			i = i - to_find_count;
			to_find_count = 0;
		}
		else
			to_find_count += 1;
		if (to_find_count == size)
		{
			return (str - size + i + 1);
		}
		i++;
	}
	return (0);
}
