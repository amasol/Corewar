/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:47:52 by bdomansk          #+#    #+#             */
/*   Updated: 2018/10/30 17:47:54 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** while (42) == цикл пока чемпион не будет определен
** в визуализацию еще нужно добавить номер текущего цикла ( )
*/

void		standart_output(t_vm *vm)
{
	introducing_contestants(vm);
	while (vm->current_cycle < 10000)
	{
		if (vm->flags->dump && vm->current_cycle == vm->flags->dump_value)
		{
			print_map(vm);
			break ;
		}
		vm->current_cycle++;
		perform_carriages(vm);
		if (vm->cycle_to_die < 0 || vm->cycle_check == vm->current_cycle)
			check_carriages(vm);
	}
}

void		visulization(t_vm *vm)
{
	visualization_init(vm);
	if (vm->flags->m)
		sdl_mixer_init(vm);
	while (42)
	{
		if (!check_key(getch(), vm))
			break ;
		werase(vm->w);
		werase(vm->info);
		draw_map(vm);
		draw_info_table(vm);
		wrefresh(vm->w);
		wrefresh(vm->info);
		usleep(vm->delay / vm->cycles);
	}
	close_visulization(vm);
}

int			main(int argc, char **argv)
{
	t_vm	*vm;

	vm = init_info(argc, argv);
	parse_arguments(vm);
	define_bots_id(vm);
	fill_map(vm);
	(vm->flags->v) ? visulization(vm) : standart_output(vm);
	print_winner(vm);
	return (0);
}
