/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:10:59 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/25 17:11:00 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern const t_operations g_operations[16];

static void	live_bot(t_vm *vm, int i, int position)
{
	if (vm->flags->v)
	{
		vm->map[position].temp_color = vm->bot[i].id + 20;
		vm->map[position].cycles = 50;
	}
	vm->last_live_bot = &vm->bot[i];
	vm->bot[i].lives_current_period++;
	vm->bot[i].cycle_last_live = vm->current_cycle;
	if (vm->flags->lives && !vm->flags->v)
		ft_printf("Player %d (%s) is said to be alive\n",
		vm->bot[i].id, vm->bot[i].name);
}

void		ft_live(t_vm *vm, t_carriage *carriage)
{
	int	argument;
	int	i;
	int	size;

	carriage->alive = 1;
	vm->number_of_lives++;
	carriage->cycle_last_live = vm->current_cycle;
	size = SIZE_DIR(carriage->opcode);
	argument = (int)get_arg_from_map(vm->map, carriage->position + 1, size);
	i = 0;
	if (vm->flags->ops && !vm->flags->v)
		ft_printf("P %4d | live %d\n", carriage->id, argument);
	while (i < vm->number_of_bots)
	{
		if (argument == -vm->bot[i].id)
		{
			live_bot(vm, i, carriage->position);
			break ;
		}
		i++;
	}
	move_carriage(vm, carriage);
}
