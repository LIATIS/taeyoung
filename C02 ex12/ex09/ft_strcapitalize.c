/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:25:08 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/04 17:26:46 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		condition_chk(char *str)
{
	if (*str >= 48 && *str <= 57)
		return (0);
	else if (*str >= 65 && *str <= 90)
		return (1);
	else if (*str >= 97 && *str <= 122)
		return (2);
	else
		return (3);
}

void	set_capital(char *str, int *capital)
{
	if (*capital == 1)
	{
		if (*str <= 'z' && *str >= 'a')
			*str -= 'z' - 'Z';
	}
	else
	{
		if (*str <= 'Z' && *str >= 'A')
			*str += 'z' - 'Z';
	}
	*capital = 0;
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		check;
	int		capital;

	i = 0;
	check = 1;
	capital = 1;
	while (*(str + i) != '\0')
	{
		check = condition_chk(str + i);
		if (check == 0)
			capital = 0;
		else if (check == 1 || check == 2)
			set_capital((str + i), &capital);
		else
			capital = 1;
		i++;
	}
	return (str);
}
