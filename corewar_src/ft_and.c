/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:50:55 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/05 13:50:56 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_and(t_vm *vm, t_carriage *carriage)
{
	int				argument1;
	int				argument2;
	int				position;
	unsigned char	reg_id;

	argument1 = get_arg_by_type(vm, carriage, 0);
	argument2 = get_arg_by_type(vm, carriage, 1);
	position = get_arg_position(carriage, 2);
	reg_id = (unsigned char)get_arg_from_map(vm->map, position, 1);
	carriage->registers[reg_id] = argument1 & argument2;
	carriage->carry = (carriage->registers[reg_id] == 0) ? 1 : 0;
	if (!vm->flags->v && vm->flags->ops)
		ft_printf("P %4d | and %d %d r%d\n",
		carriage->id, argument1, argument2, reg_id);
	move_carriage(vm, carriage);
}
