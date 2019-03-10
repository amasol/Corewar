/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:16:47 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/09 15:16:48 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_sti(t_vm *vm, t_carriage *carriage)
{
	int				arg2;
	int				arg3;
	int				position;
	int				value;
	unsigned char	reg_id;

	position = carriage->position + 1;
	reg_id = (unsigned char)get_arg_from_map(vm->map, position, 1);
	value = carriage->registers[reg_id];
	arg2 = get_arg_by_type(vm, carriage, 1);
	arg3 = get_arg_by_type(vm, carriage, 2);
	rewrite_map(vm, carriage, value, (arg2 + arg3) % IDX_MOD);
	if (!vm->flags->v && vm->flags->ops)
	{
		ft_printf("P %4d | sti r%d %d %d\n",
		carriage->id, reg_id, arg2, arg3);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		arg2, arg3, arg2 + arg3,
		carriage->position - 1 + ((arg2 + arg3) % IDX_MOD));
	}
	move_carriage(vm, carriage);
}
