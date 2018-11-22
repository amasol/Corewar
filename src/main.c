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
//int			main(int argc, char **argv)
int 		main(void)
{
	t_val bot;
	bot = s_file();

//	processing_function(bot);

i = 0;
j = 0;

while (av[i]) {
	if(av[i][0] == '-'){
		parsingFlag(av[i]);
	} else {
		parsingBot(av[i], structBot);
	}
	i++;
}

void parsingFlag(char *arg){
	int i = 1;
	while (arg[i]){
		if(arg[i] = 'n')
			strucFlag->n = 1;
		else if(arg[i] = 'l')
			strucFlag->n = 1;
		else
			i++;
		i++;
	}
}

void parsingBot(char *arg, struct structBot) {
	fd = open(arg);

}


//	system("leaks corewar");
	return (0);
}
