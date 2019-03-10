/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:43:09 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/21 11:43:10 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	music_key(t_vm *vm)
{
	if (!vm->music_init)
		sdl_mixer_init(vm);
	else
	{
		vm->music_init = 0;
		Mix_PauseMusic();
	}
}

int		check_key(int ch, t_vm *vm)
{
	int cycles;

	cycles = vm->cycles_in_second;
	if (ch == 'q')
		vm->cycles_in_second = ((cycles + 100) > 1000) ? 1000 : cycles + 100;
	if (ch == 'w')
		vm->cycles_in_second = ((cycles + 10) > 1000) ? 1000 : cycles + 10;
	if (ch == 'e')
		vm->cycles_in_second = ((cycles + 1) > 1000) ? 1000 : cycles + 1;
	if (ch == 'y')
		vm->cycles_in_second = ((cycles - 100) < 1) ? 1 : cycles - 100;
	if (ch == 't')
		vm->cycles_in_second = ((cycles - 10) < 1) ? 1 : cycles - 10;
	if (ch == 'r')
		vm->cycles_in_second = ((cycles - 1) < 1) ? 1 : cycles - 1;
	if (ch == 'd')
		vm->cycles_in_second = 10;
	if (vm->running && ch == ' ')
		npause(vm);
	if (ch == 'm' && vm->running)
		music_key(vm);
	if (ch == 27)
		close_visulization(vm);
	return (ch);
}
