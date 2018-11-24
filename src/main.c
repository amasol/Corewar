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
int			main(int argc, char **argv)
//int 		main(void)
{
	int		j;
	int		i;
	t_val	bot;

	i = 1;
	j = 0;
//	bot = s_file();

//	processing_function(bot);


	if (argv[i])
	{
		if(argv[i][0] == '-')
		{
			printf("test key");
	//		parsingflag(argv[i]);
			;
		}
		else
			bot = s_file(argv[i]);
	//		parsingBot(av[i], structBot);
		i++;
	}


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

void parsingBot(char *arg, struct structBot)
{
	fd = open(arg);

}
*/

//	system("leaks corewar");
	return (0);
}
