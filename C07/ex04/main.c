/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:12:26 by tae-kim           #+#    #+#             */
/*   Updated: 2020/06/17 12:03:13 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

extern int				chk_validation(char *base);
extern int				chk_base(char *str, char *base);
extern int				chk_front_char(char *str, int *i, char *base);
extern unsigned int	chk_back_int(char *str, int *i, char *base, int size);
extern char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
extern char				*make_pointer_with_size(int *to_char_size, int plus);
extern unsigned int		size_of_basechar(unsigned int num, unsigned int size);
extern void				chg_char(unsigned int num, char *r_c, char *b_t, int s_t);

int main(void) {
	printf("%s",ft_convert_base("   ---2121312d0", "0123456789", "A123456789"));
	return 0;
}