/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:22:15 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/21 10:22:16 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	draw_elem(t_vm *vm, int i, int pair)
{
	wattron(vm->w, COLOR_PAIR(pair));
	mvwprintw(vm->w, vm->y, vm->x, "%0.2x", vm->map[i].cell);
	wattroff(vm->w, COLOR_PAIR(pair));
}

static int	check_carriage(t_vm *vm, unsigned int pos)
{
	t_carriage *temp;

	temp = vm->carriage;
	while (temp)
	{
		if (temp->position == pos)
			return (temp->parent->id);
		temp = temp->next;
	}
	return (0);
}

void		draw_map(t_vm *vm)
{
	int car_id;
	int i;

	vm->x = 2;
	vm->y = 1;
	i = 0;
	while (i < MEM_SIZE)
	{
		if ((car_id = check_carriage(vm, i)))
			draw_elem(vm, i, vm->map[i].color + 10);
		else if (vm->map[i].cycles)
		{
			draw_elem(vm, i, vm->map[i].temp_color);
			if (vm->running)
				vm->map[i].cycles--;
		}
		else
			draw_elem(vm, i, vm->map[i].color);
		i++;
		vm->x += 3;
		vm->y = (vm->x >= 192) ? vm->y + 1 : vm->y;
		vm->x = (vm->x >= 192) ? 2 : vm->x;
		vm->y = (vm->y > 64) ? 1 : vm->y;
	}
}
