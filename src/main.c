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

int		parse_args(int ac, char **av, t_bot *bot, int i)
{
	while (av[i]) //av[i] && ac <= 5
	{
		if(av[i][0] == '-')
		{
			printf("test key");
			//parsingflag(av[i]); // будет парсится те флаги которые входят
		}
		else
			bot[i - 1] = read_file(av[i], i);
		i++;
	}
	return (i - 1);
}

void	new_carriage(t_carriage **carriage, int pos, int id, int parent)
{
	t_carriage *new;
	t_carriage *iter;

	if (!(new = malloc(sizeof(t_carriage))))
		ft_error("Memory allocation error");
	new->position = pos;
	new->carry = 0; // ?
	new->player_id = id + 1;
	new->alive = 0; // ?
	new->exec_command = 0; // ?
	new->number_cycle = 0; // ?
	new->next = NULL;
	if (!(*carriage))
		*carriage = new;
	else
	{
		new->next = *carriage;
		*carriage = new;
	}
}

void		fill_map(t_carriage **carriage, t_bot bot[])
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	while (j < MEM_SIZE)
	{
		if (j == i * MEM_SIZE / g_base->bots)
		{
			new_carriage(carriage, i * MEM_SIZE / g_base->bots, i, -1);
			size = bot[i].size;
			while (size-- > 0)
			{				
				g_base->map[j].cell = bot[i].exec_code[bot[i].size - size - 1];
				g_base->map[j].color = bot[i].id;
				j++;
			}
			i++;
		}		
		g_base->map[j].cell = 0;
		g_base->map[j].color = 10;
		j++;
	}
}



int			main(int argc, char **argv)
{
	t_bot		bot[4];
	t_carriage	*carriage;

	if (argc >= 6)
		ft_error("Too many arguments");
	carriage = NULL;

	g_base = malloc(sizeof(t_base));
	g_base->bots = parse_args(argc, argv, &(*bot), 1);
	g_base->bot = bot;
	fill_map(&carriage, bot);
	
	//if visualization flag
		visualization_init();

	while (42) //while (cycle_to_die > 0)
	{
		visualization(carriage);
		/* ПРОСТО ТЕСТ ДВИЖЕНИЯ КАРЕТКИ, МОЖНО УБРАТЬ */
		t_carriage *tmp = carriage;
		while (tmp)
		{
			
			tmp->position += 1;
			if (tmp->position == MEM_SIZE)
				tmp->position = 0;
			tmp = tmp->next;
		}
		/**********************************************/

	}

	// эти функции очищают память окна визуалиции и закрывают его.
	// выполнить только после выхода из окна CRTL + C
	// придумать как это правильно обработать, 
	// после окнчания цикла cycle_to_die они завершатся автоматически
	// ВЫПОЛНИТЬ ТОЛЬКО ЕСЛИ ИНИЦИАЛИЗИРОВАНА ВИЗУАЛИЗАЦИЯ
	delwin(g_base->w);
	delwin(g_base->info);
	endwin();
	
/*******************************************************************************/
	//	print map
 // 	int i = -1;
	// while (++i < MEM_SIZE)
	// {
	// 	if (g_map[i].cell)
	// 		printf("\033[92m%0.2x\033[0m ", g_map[i].cell);
	// 	else
	// 		printf("\033[90m00\033[0m ");
	// }
	// printf("\n");
/*******************************************************************************/

/*******************************************************************************/
	//print carriage info
	// while (carriage)
	// {
	// 	printf("carri: id = %d, pos = %d\n", carriage->player_id, 
	//	carriage->position);
	// 	printf("car commnd = %0.2x\n", g_map[carriage->position]);
	// 	carriage = carriage->next;
	// }
/*******************************************************************************/


//	system("leaks corewar");
	return (0);
}
