/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npause.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:28:03 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/22 12:28:04 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		npause(t_vm *vm)
{
	vm->running = 0;
	Mix_PauseMusic();
	while (!vm->running)
	{
		werase(vm->info);
		werase(vm->w);
		draw_map(vm);
		draw_info_table(vm);
		draw_phrase(vm);
		wattron(vm->info, COLOR_PAIR(4));
		wattron(vm->info, A_BLINK);
		mvwprintw(vm->info, 1, 3, "STOPED");
		(vm->music) ? mvwprintw(vm->info, 1, 30, "MUSIC: Stoped") : 0;
		wattroff(vm->info, COLOR_PAIR(4));
		wattroff(vm->info, A_BLINK);
		(vm->music == NULL) ? mvwprintw(vm->info, 1, 30, "MUSIC: OFF") : 0;
		if (check_key(getch(), vm) == ' ')
		{
			if (vm->music_init)
				Mix_ResumeMusic();
			vm->running = 1;
		}
		wrefresh(vm->info);
		wrefresh(vm->w);
	}
}

void		draw_phrase(t_vm *vm)
{
	mvwprintw(vm->info, 63, 10, " (MAY THE FORCE BE WITH YOU)");
}

static void	draw_winner(t_vm *vm)
{
	wattron(vm->info, COLOR_PAIR(vm->last_live_bot->id));
	mvwprintw(vm->info, 63, 10, " (WINNER: %s)", vm->last_live_bot->name);
	wattroff(vm->info, COLOR_PAIR(vm->last_live_bot->id));
}

void		winner(t_vm *vm)
{
	vm->running = 0;
	Mix_PauseMusic();
	while (!vm->running)
	{
		werase(vm->info);
		werase(vm->w);
		draw_map(vm);
		draw_info_table(vm);
		draw_winner(vm);
		wattron(vm->info, A_BLINK);
		mvwprintw(vm->info, 1, 3, "END");
		(vm->music) ? mvwprintw(vm->info, 1, 30, "MUSIC: Stoped") : 0;
		wattroff(vm->info, A_BLINK);
		(vm->music == NULL) ? mvwprintw(vm->info, 1, 30, "MUSIC: OFF") : 0;
		if (check_key(getch(), vm) == ' ')
		{
			if (vm->music_init)
				Mix_ResumeMusic();
			vm->running = 1;
		}
		wrefresh(vm->info);
		wrefresh(vm->w);
	}
}
