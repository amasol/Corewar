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

/**
	=== new_carriage ===
	parent - если значение -1, значит это новая каретка, 
	иначе ищем каретку, которая порадила новую карету и добавляем новую после нее
	что бы передать ход новой каретке

	если не хватит переменных передаваемых в функцию, 
	вынести вставку порожденной каретки в другую функцию
**/

void	new_carriage(t_carriage **carriage, int pos, int id, int parent)
{
	t_carriage *new;
	t_carriage *iter;

	new = malloc(sizeof(t_carriage));
	new->position = pos;
	new->carry = 0; // ?
	new->player_id = id;
	new->alive = 0; // ?
	new->exec_command = 0; // ?
	new->number_cycle = 0; // ?
	new->next = NULL;
	if (!(*carriage))
		*carriage = new;
	else
	{
		iter = *carriage;
		while (iter->next && iter->player_id != parent)
			iter = iter->next;
		new->next = iter->next;
		iter->next = new;
	}
}


int			main(int argc, char **argv)
{
	int 		bots;
	int i;
	t_val		bot[4];
	t_carriage	*carriage;

	bots = 0;
	carriage = NULL;
	while (argv[bots + 1] && argc <= 5)
	{
		if(argv[bots + 1][0] == '-')
		{
			printf("test key");
			//parsingflag(argv[i]); // будет парсится те флаги которые входят
		}
		else
			bot[bots] = s_file(argv[bots + 1]);
		bots++;
	}
	if (argc >= 6)
		error("many arguments");


	ft_bzero(g_map, MEM_SIZE);

	i = -1;
	while (++i < bots)
	{
		new_carriage(&carriage, i * MEM_SIZE / bots, i, -1); // carriage initialization
		ft_memcpy(g_map + i * MEM_SIZE / bots, bot[i].executable_code, bot[i].b_size_int);

		/* print posotion */
		//printf("position = %d, size = %zu\n", i * MEM_SIZE / bots, bot[i].b_size_int);
	}

//	first_carr = carriage;
// 	carriage.position = -1;
// 	bots = 1;
// //	возвращаем значение сдвинутой каретки
// 	if (++carriage.position < MEM_SIZE)
// 	{
// 		processing_function(&bot[1], &carriage);
// 	}
	
//	после создания карты, мы должны запустить наш цыкл и расставить дефолтные значения


/*******************************************************************************/
	//	print map
 	i = -1;
	while (++i < MEM_SIZE)
	{
		if (g_map[i])
			printf("%0.2x ", g_map[i]);
		else
			printf(".. ");
	}
	printf("\n");
/*******************************************************************************/

/*******************************************************************************/
	//print carriage info
	while (carriage)
	{
		printf("carriage:    id = %d, pos = %d\n", carriage->player_id, carriage->position);
		printf("car commnd = %0.2x\n", g_map[carriage->position]);
		carriage = carriage->next;
	}
/*******************************************************************************/


	//	использовать функцию processing_function(bot, &carriage);
	// как пользоваться структоруй op.c

//	system("leaks corewar");
	return (0);
}
