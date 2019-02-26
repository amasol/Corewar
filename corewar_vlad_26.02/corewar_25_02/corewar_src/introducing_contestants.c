/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introducing_contestants.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:14:35 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/22 15:14:36 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	colour_introducing(t_vm *vm)
{
	t_bot	bot;
	int		i;

	i = 0;
	ft_printf("\033[90mIntroducing contestants...\n\033[0m");
	while (i < vm->number_of_bots)
	{
		bot = vm->bot[i];
		if (bot.id == 1)
			ft_printf("%s", YELLOW);
		else if (bot.id == 2)
			ft_printf("%s", GREEN);
		else if (bot.id == 3)
			ft_printf("%s", BLUE);
		else if (bot.id == 4)
			ft_printf("%s", RED);
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
		bot.id, bot.prog_size, bot.name, bot.comment);
		ft_printf("%s", DEF);
		i++;
	}
}

void		introducing_contestants(t_vm *vm)
{
	t_bot	bot;
	int		i;

	i = 0;
	if (vm->flags->c)
		colour_introducing(vm);
	else
	{
		ft_printf("Introducing contestants...\n");
		while (i < vm->number_of_bots)
		{
			bot = vm->bot[i];
			ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
			bot.id, bot.prog_size, bot.name, bot.comment);
			i++;
		}
	}
}
