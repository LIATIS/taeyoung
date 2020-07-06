/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:55:47 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/08 11:48:57 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (*(s1 + i) != '\0' || *(s2 + i) != '\0')
	{
		if (*(s1 + i) > *(s2 + i))
			return (1);
		else if (*(s1 + i) < *(s2 + i))
			return (-1);
		i++;
	}
	return (0);
}

void	print_char(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (*(*(argv + i) + j) != '\0')
		{
			write(1, *(argv + i) + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	char	*num;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				num = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = num;
			}
			j++;
		}
		i++;
	}
	print_char(argc, argv);
}
