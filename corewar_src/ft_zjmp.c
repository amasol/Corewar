/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:07:39 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/28 12:07:41 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern const t_operations g_operations[16];

void	ft_zjmp(t_vm *vm, t_carriage *carriage)
{
	unsigned int	pos;
	short			jump_len;
	short			size;
	char			*carry;

	pos = carriage->position;
	size = SIZE_DIR(carriage->opcode);
	if (vm->flags->ops && !vm->flags->v)
	{
		carry = (carriage->carry) ? "OK" : "FAILED";
		jump_len = (short)get_arg_from_map(vm->map, pos + 1, size);
		ft_printf("P %4d | zjmp %d %s\n", carriage->id, jump_len, carry);
	}
	if (carriage->carry)
	{
		jump_len = (short)get_arg_from_map(vm->map, pos + 1, size) % IDX_MOD;
		carriage->position = (pos + jump_len) % MEM_SIZE;
	}
	else
		move_carriage(vm, carriage);
}
