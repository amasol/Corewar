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

void		standart_output(t_vm *vm)
{
	introducing_contestants(vm);
	while (vm->current_num_of_carriages)
	{
		if (vm->flags->dump && vm->current_cycle == vm->flags->dump_value)
		{
			print_map(vm);
			break ;
		}
		vm->current_cycle++;
		if (vm->flags->cycles)
			ft_printf("It is now cycle %d\n", vm->current_cycle);
		perform_carriages(vm);
		if (vm->cycle_check == vm->current_cycle)
			check_carriages(vm);
	}
	print_winner(vm);
}

void		visulization(t_vm *vm)
{
	visualization_init(vm);
	npause(vm);
	while (vm->current_num_of_carriages)
	{
		check_key(getch(), vm);
		werase(vm->w);
		werase(vm->info);
		draw_map(vm);
		draw_info_table(vm);
		draw_phrase(vm);
		vm->current_cycle++;
		perform_carriages(vm);
		if (vm->cycle_check == vm->current_cycle)
			check_carriages(vm);
		wrefresh(vm->w);
		wrefresh(vm->info);
		usleep(vm->delay / vm->cycles_in_second);
	}
	winner(vm);
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
	return (0);
}
