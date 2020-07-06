/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae-kim <tae-kim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 17:40:58 by jeeshin           #+#    #+#             */
/*   Updated: 2020/06/18 04:58:20 by tae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char **argv)
{
	int i;

	if (argc == 1) //파일이 인자로 하나도 들어오지 않았을 때
	{
		parse_stdin(); //표준입력으로 받아서 // 출력까지 한번에 스트레이트
		return (0);
	}
	i = 1;
	while (i < argc) //파일 1개 이상이 인자로 들어왔을 때
	{
		if (parse_file(argv[i])) // 파일을 입력 받는 동시에 확인 출력
			print_error(0);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
