/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:57:28 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/09 13:57:29 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_ldi(t_vm *vm, t_carriage *carriage)
{
	int	value1;
	int	value2;
	int	position;
	int	id_reg;

	value1 = get_arg_by_type(vm, carriage, 0);
	value2 = get_arg_by_type(vm, carriage, 1);
	position = get_arg_position(carriage, 2);
	id_reg = (unsigned char)get_arg_from_map(vm->map, position, 1);
	position = carriage->position - 1 + ((value1 + value2) % IDX_MOD);
	carriage->registers[id_reg] = get_arg_from_map(vm->map, position, 4);
	if (!vm->flags->v && vm->flags->ops)
	{
		ft_printf("P %4d | ldi %d %d r%d\n",
		carriage->id, value1, value2, id_reg);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
		value1, value2, value1 + value2, position);
	}
	move_carriage(vm, carriage);
}
