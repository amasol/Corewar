/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:39:19 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/09 19:39:21 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_lfork(t_vm *vm, t_carriage *carriage)
{
	int				address;
	int				position;

	address = get_arg_by_type(vm, carriage, 0);
	position = carriage->position + (address);
	position = position % MEM_SIZE;
	new_carriage(vm, carriage->parent, position);
	copy_carriage_data(vm->carriage, carriage);
	if (!vm->flags->v && vm->flags->ops)
		ft_printf("P %4d | lfork  %d (%d)\n",
		carriage->id, address, position);
	move_carriage(vm, carriage);
}
