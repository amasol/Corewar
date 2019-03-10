/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:50:02 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/09 19:50:04 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_lld(t_vm *vm, t_carriage *carriage)
{
	int	value;
	int	position;
	int	id_reg;

	value = get_arg_by_type(vm, carriage, 0);
	position = get_arg_position(carriage, 1);
	id_reg = (unsigned char)get_arg_from_map(vm->map, position, 1);
	carriage->carry = (value == 0) ? 1 : 0;
	carriage->registers[id_reg] = value;
	if (!vm->flags->v && vm->flags->ops)
		ft_printf("P %4d | lld %d r%d\n", carriage->id, value, id_reg);
	move_carriage(vm, carriage);
}
