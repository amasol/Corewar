/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:50:50 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/21 12:50:52 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** в draw_info, draw_bots данные будут меняться
*/

static void	draw_bots(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->number_of_bots)
	{
		wattron(vm->info, COLOR_PAIR(vm->bot[i].id));
		mvwprintw(vm->info, 5 + (i * 6), 3, "Champ : %s\n", vm->bot[i].name);
		wattroff(vm->info, COLOR_PAIR(vm->bot[i].id));
		mvwprintw(vm->info, 5 + (i * 6) + 1, 5, "Lives\t\t%d\n", 0);
		mvwprintw(vm->info, 5 + (i * 6) + 2, 5, "Something else\t%d\n", 0);
		i++;
	}
}

static void	draw_duck(t_vm *vm)
{
	mvwprintw(vm->info, 62, 1, "      _\n");
	mvwprintw(vm->info, 63, 1, "  .__(.)< (MAY THE FORCE BE WHITH YOU)\n");
	mvwprintw(vm->info, 64, 1, "  \\___)   \n");
}

static void	draw_run(t_vm *vm)
{
	if (vm->running)
	{
		wattron(vm->info, COLOR_PAIR(2));
		mvwprintw(vm->info, 1, 3, "RUNING\n");
		if (vm->music_init == 1)
			mvwprintw(vm->info, 1, 30, "MUSIC: Play\n");
		wattroff(vm->info, COLOR_PAIR(2));
		if (vm->music == NULL)
			mvwprintw(vm->info, 1, 30, "MUSIC: OFF\n");
		wattron(vm->info, COLOR_PAIR(4));
		wattron(vm->info, A_BLINK);
		if (!vm->music_init && vm->music)
			mvwprintw(vm->info, 1, 30, "MUSIC: Stoped\n");
		wattroff(vm->info, COLOR_PAIR(4));
		wattroff(vm->info, A_BLINK);
	}
}

static void	draw_info(t_vm *vm)
{
	int n;

	n = 5 + (vm->number_of_bots * 6) + 2;
	draw_run(vm);
	mvwprintw(vm->info, 3, 3, "Cycles/second : %d\n", vm->cycles);
	mvwprintw(vm->info, 58, 3, "Q : +100\tW : +10\t\tE : +1\n");
	mvwprintw(vm->info, 59, 3, "R : -1\tT : -10\t\tY : -100\n");
	mvwprintw(vm->info, n, 3, "CYCLE_TO_DIE\t\t%d\n", CYCLE_TO_DIE);
	mvwprintw(vm->info, n + 2, 3, "CYCLE_DELTA\t\t%d\n", CYCLE_DELTA);
	mvwprintw(vm->info, n + 4, 3, "NBR_LIVE\t\t%d\n", NBR_LIVE);
	mvwprintw(vm->info, n + 6, 3, "MAX_CHECKS\t\t%d\n", MAX_CHECKS);
}

void		draw_info_table(t_vm *vm)
{
	draw_info(vm);
	draw_bots(vm);
	draw_duck(vm);
	wattron(vm->w, COLOR_PAIR(10));
	wattron(vm->info, COLOR_PAIR(10));
	box(vm->w, 0, 0);
	box(vm->info, 0, 0);
	mvwhline(vm->info, 5 + (vm->number_of_bots * 6), 1, ACS_HLINE, 48);
	wattroff(vm->w, COLOR_PAIR(10));
	wattroff(vm->info, COLOR_PAIR(10));
}
