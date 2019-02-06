/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:41:46 by amasol            #+#    #+#             */
/*   Updated: 2018/10/31 15:41:47 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

/*
void parsingFlag(char *arg)
{
	int i;

	i = 1;
	while (arg[i])
	{
		if(arg[i] = 'n')
			strucFlag->n = 1;
		else if(arg[i] = 'l')
			strucFlag->n = 1;
		else
			i++;
		i++;
	}
}

*/

unsigned char	g_map[MEM_SIZE];

int			main(int argc, char **argv)
{
	int 		bots;
	t_val		bot[4];
	int i;
//	t_val		bot;
	t_carriage	carriage;
//	t_carriage	first_carr;

	bots = 0;
	while (argv[bots + 1] && argc <= 5)
	{
		if(argv[bots + 1][0] == '-')
		{
			printf("test key");
			//parsingflag(argv[i]); // будет парсится те флаги которые входят
		}
		else{
			bot[bots] = s_file(argv[bots + 1]);
		}
		bots++;
	}

	if (argc >= 6)
		error("many arguments");

/*
	i = 0;
	while (i < 4)
		printf("%x", bot[1].m_header[i++]);
	i = 0;
	printf("\n");
	while (i < PROG_NAME_LENGTH)
		printf("%x", bot[1].bot_name[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", bot[1].b_size[i++]);
	printf("\n");
	i = 0;
	while (i < COMMENT_LENGTH)
		printf("%x", bot[1].b_comment[i++]);
	printf("\n");
	i = 0;
	while (i < bot[1].b_size_int)
		printf("%x", bot[1].executable_code[i++]);
	printf("\n");
*/


//	first_carr = carriage;
// 	carriage.position = -1;
// 	bots = 1;
// //	возвращаем значение сдвинутой каретки
// 	if (++carriage.position < MEM_SIZE)
// 	{
// 		processing_function(&bot[1], &carriage);
// 	}

	ft_bzero(g_map, MEM_SIZE);
	i = -1;
	while (++i < bots)
	{
		ft_memcpy(g_map + i * MEM_SIZE / bots, bot[i].executable_code, bot[i].b_size_int);

	}
	i = -1;

	// while (++i < bot[1].b_size_int)
	// {
	// 	printf("%x ", bot[1].executable_code[i]);
	// }
	while (++i < MEM_SIZE)
	{
		if (g_map[i])
			printf("%0.2x ", g_map[i]);
		else
			printf(".. ");
	}
	printf("\n");

	printf("i = %d\n", i);



	//  разбил ботами карту на столько частей сколько нужно!
	//	использовать функцию processing_function(bot, &carriage);
	// как пользоваться структоруй op.c

//	system("leaks corewar");
	return (0);
}
