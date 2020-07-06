/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:25:08 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/04 21:33:44 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) > 'z' || *(str + i) < 'A')
			return (0);
		else if (*(str + i) < 'a' && *(str + i) > 'Z')
			return (0);
		i++;
	}
	return (1);
}