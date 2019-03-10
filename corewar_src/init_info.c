/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:40:27 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/12 10:40:29 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->h = 0;
	flags->l = 0;
	flags->c = 0;
	flags->v = 0;
	flags->m = 0;
	flags->n = 0;
	flags->dump = 0;
	flags->dump_value = 0;
	flags->dump_bytes = 0;
	flags->lives = 0;
	flags->cycles = 0;
	flags->ops = 0;
	flags->deaths = 0;
	flags->moves = 0;
	return (flags);
}

static void		init_available_ids(t_vm *info)
{
	int i;

	i = 0;
	while (i < 5)
	{
		info->available_id[i] = 0;
		i++;
	}
}

static void		init_lives(t_vm *info)
{
	info->previous_lives[0] = 0;
	info->previous_lives[1] = 0;
	info->previous_lives[2] = 0;
	info->previous_lives[3] = 0;
	info->current_lives[0] = 0;
	info->current_lives[1] = 0;
	info->current_lives[2] = 0;
	info->current_lives[3] = 0;
}

t_vm			*init_info(int argc, char **argv)
{
	t_vm	*info;

	info = (t_vm*)malloc(sizeof(t_vm));
	info->flags = init_flags();
	init_available_ids(info);
	init_lives(info);
	info->number_of_bots = 0;
	info->num_of_carriages = 0;
	info->error_reason = NULL;
	info->fd = 0;
	info->argc = argc;
	info->argv = argv;
	info->current_cycle = 0;
	info->music_init = 0;
	info->music = NULL;
	info->cycle_to_die = CYCLE_TO_DIE;
	info->cycle_check = info->cycle_to_die;
	info->number_of_checks = 0;
	info->number_of_lives = 0;
	info->last_live_bot = NULL;
	if (argc == 1)
		put_manual(info);
	return (info);
}
