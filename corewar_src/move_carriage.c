/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_carriage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:03:08 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/03 15:03:09 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern const t_operations g_operations[16];

static void	show_carriage_move(t_vm *vm, t_carriage *carriage)
{
	int	i;
	int	start;
	int	finish;
	int	move_len;

	start = carriage->position - CODE_TYPE(carriage->opcode);
	start = ((unsigned int)start) % MEM_SIZE;
	move_len = 1 + CODE_TYPE(carriage->opcode);
	i = 0;
	while (i < carriage->number_of_arguments)
	{
		move_len = move_len + get_size_by_type(carriage, i);
		i++;
	}
	finish = (start + move_len) % MEM_SIZE;
	ft_printf("ADV %d (0x%04x -> 0x%04x) ", move_len, start, finish);
	i = 0;
	while (i < move_len)
		ft_printf("%02x ",
		(unsigned char)get_arg_from_map(vm->map, start + i++, 1));
	ft_printf("\n");
}

void		move_carriage(t_vm *vm, t_carriage *carriage)
{
	int	new_position;
	int i;

	new_position = carriage->position + 1;
	i = 0;
	while (i < carriage->number_of_arguments)
	{
		new_position = new_position + get_size_by_type(carriage, i);
		i++;
	}
	if (vm->flags->moves && !vm->flags->v)
		show_carriage_move(vm, carriage);
	carriage->position = new_position % MEM_SIZE;
}
