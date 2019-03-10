/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:05:55 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/07 20:05:58 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_st(t_vm *vm, t_carriage *carriage)
{
	int				address;
	int				position;
	int				value;
	unsigned char	reg_id;

	position = carriage->position + 1;
	reg_id = (unsigned char)get_arg_from_map(vm->map, position, 1);
	value = carriage->registers[reg_id];
	if (carriage->arg_type[1] == T_REG)
	{
		address = get_arg_by_type(vm, carriage, 1);
		carriage->registers[address] = value;
	}
	else
	{
		position = get_arg_position(carriage, 1);
		address = (short)get_arg_from_map(vm->map, position, IND_SIZE);
		address = address % IDX_MOD;
		rewrite_map(vm, carriage, value, address);
	}
	if (!vm->flags->v && vm->flags->ops)
		ft_printf("P %4d | st r%d %d\n",
		carriage->id, reg_id, address);
	move_carriage(vm, carriage);
}
