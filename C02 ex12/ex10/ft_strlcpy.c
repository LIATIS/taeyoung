/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:25:08 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/04 21:33:19 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *str)
{
	unsigned int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		i;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (*(src + i) != '\0' && i < size - 1)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (ft_strlen(src));
}
