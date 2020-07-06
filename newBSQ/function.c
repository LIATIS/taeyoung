/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 04:17:01 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/18 05:40:56 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	unsigned int		i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char 	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (n && (i < n) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_strcat(char *desti, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (desti[i] != '\0')
		i++;
	while (src[j] != '\0')
		desti[i++] = src[j++];
	desti[i] = '\0';
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		i;
	unsigned int		size;

	size = ft_strlen(dest);
	i = 0;
	while (*(src + i) != '\0' && i < nb)
	{
		*(dest + size + i) = *(src + i);
		i++;
	}
	*(dest + size + i) = '\0';
	return (dest);
}

int		ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result + str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}