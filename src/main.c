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

unsigned char	g_map[MEM_SIZE];

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




int			main(int argc, char **argv)
{
	int 		bots;
	t_val		bot[4];
	int i;
//	t_val		bot;
//	t_carriage	carriage;

	bots = 1;
	while (argv[bots] && argc < 4)
	{
		if(argv[bots][0] == '-')
		{
			printf("test key");
//			parsingflag(argv[i]); // будет парсится те флаги которые входят
		}
		else
			bot[bots] = s_file(argv[bots]);
//			processing_function(bot, &carriage); // <- возможно это функцию нужно вынести в дргуой
// 				цыкл что бы у уже ходить конкретно по тем коретка которые будут
		bots++;
	}

	if (argc >= 6)
		error("many arguments");

/*
	ft_bzero(g_map, MEM_SIZE);
	i = -1;
	while (++i < bots)
	{
		ft_memcpy(g_map + i * MEM_SIZE / bots, bot[i].executable_code, bot[i].b_size_int);

	}
	//  разбил ботами карту на столько частей сколько нужно!
	//	 как я буду ходить каретками по тем ботам что есть на карте ?
	// это нужно в каждый момент заходить выпонлнять функцию и делать переключение
	// 	в конкретную карту бота и идти по картеке,
	//	использовать функцию processing_function(bot, &carriage);
	// как пользоваться структоруй op.c
*/
//	system("leaks corewar");
	return (0);
}
