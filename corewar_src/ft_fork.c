/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:54:55 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/09 15:54:56 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_fork(t_vm *vm, t_carriage *carriage)
{
	int				address;
	int				position;

	address = get_arg_by_type(vm, carriage, 0);
	position = carriage->position + (address % IDX_MOD);
	position = position % MEM_SIZE;
	new_carriage(vm, carriage->parent, position);
	copy_carriage_data(vm->carriage, carriage);
	if (!vm->flags->v && vm->flags->ops)
		ft_printf("P %4d | fork  %d (%d)\n",
		carriage->id, address, position);
	move_carriage(vm, carriage);
}
