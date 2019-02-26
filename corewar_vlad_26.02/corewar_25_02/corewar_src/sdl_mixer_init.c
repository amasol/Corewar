/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_mixer_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:47:29 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/22 13:47:31 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sdl_mixer_init(t_vm *vm)
{
	vm->music_init = 1;
	if (vm->music)
		Mix_ResumeMusic();
	else
	{
		vm->music = NULL;
		if (SDL_Init(SDL_INIT_AUDIO) < 0)
			vm->music_init = 0;
		if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
			vm->music_init = 0;
		vm->music = Mix_LoadMUS(MUS_PATH);
		if (vm->music == NULL)
			vm->music_init = 0;
		if (Mix_PlayMusic(vm->music, -1) == -1)
			vm->music_init = 0;
	}
}
