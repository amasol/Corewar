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

void	npause(t_vm *vm)
{
	vm->running = 0;
	Mix_PauseMusic();
	while (!vm->running)
	{
		werase(vm->info);
		wattron(vm->info, COLOR_PAIR(4));
		wattron(vm->info, A_BLINK);
		mvwprintw(vm->info, 1, 3, "STOPED\n");
		if (vm->music)
			mvwprintw(vm->info, 1, 30, "MUSIC: Stoped\n");
		wattroff(vm->info, COLOR_PAIR(4));
		wattroff(vm->info, A_BLINK);
		if (vm->music == NULL)
			mvwprintw(vm->info, 1, 30, "MUSIC: OFF\n");
		draw_info_table(vm);
		wrefresh(vm->info);
		if (check_key(getch(), vm) == ' ')
		{
			if (vm->music_init)
				Mix_ResumeMusic();
			vm->running = 1;
		}
	}
}
