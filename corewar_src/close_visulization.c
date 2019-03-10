/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_visulization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:23:33 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/24 13:23:35 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	close_visulization(t_vm *vm)
{
	delwin(vm->w);
	delwin(vm->info);
	endwin();
	if (vm->music_init)
		Mix_FreeMusic(vm->music);
	Mix_CloseAudio();
	print_winner(vm);
}
