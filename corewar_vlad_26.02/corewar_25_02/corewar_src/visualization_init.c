/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:36:24 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/20 15:36:26 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Initialization of color pairs
**  1 - Yellow, 11 bkgd
**  2 - Green, 10 bkgd
**  3 - Blue 12, 4
**  4 - Red, 9 bkgd 1
** 10 - Bright Black ("Gray")
** 11 - carriage 1
** 12 - carriage 2
** 13 - carriage 3
** 14 - carriage 4
** 21 - live 1
** 22 - live 2
** 23 - live 3
** 24 - live 4
** 30 - CYAN
*/

static void	init_colors(void)
{
	initscr();
	noecho();
	curs_set(0);
	timeout(0);
	start_color();
	init_pair(1, 3, 0);
	init_pair(2, 2, 0);
	init_pair(3, 4, 0);
	init_pair(4, 9, 0);
	init_pair(10, 8, 0);
	init_pair(11, 0, 11);
	init_pair(12, 0, 10);
	init_pair(13, 0, 12);
	init_pair(14, 0, 1);
	init_pair(21, 15, 3);
	init_pair(22, 15, 2);
	init_pair(23, 15, 4);
	init_pair(24, 15, 9);
	init_pair(30, 6, 0);
}

void		visualization_init(t_vm *vm)
{
	printf("%s", vm->bot[0].name);
	init_colors();
	Mix_PlayingMusic();
	vm->w = newwin(66, 195, 0, 0);
	vm->info = newwin(66, 50, 0, 194);
	vm->delay = 1000000;
	vm->cycles = 10;
	vm->running = 1;
}
