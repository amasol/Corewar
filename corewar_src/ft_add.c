/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:45:36 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/05 16:45:39 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_add(t_vm *vm, t_carriage *carriage)
{
	int i;
	int	sum;
	int	position;
	int	id_reg[3];

	i = 0;
	while (i < 3)
	{
		position = get_arg_position(carriage, i);
		id_reg[i] = (unsigned char)get_arg_from_map(vm->map, position, 1);
		i++;
	}
	if (!vm->flags->v && vm->flags->ops)
		ft_printf("P %4d | add r%d r%d r%d\n",
		carriage->id, id_reg[0], id_reg[1], id_reg[2]);
	sum = carriage->registers[id_reg[0]] + carriage->registers[id_reg[1]];
	carriage->registers[id_reg[2]] = sum;
	carriage->carry = (sum == 0) ? 1 : 0;
	move_carriage(vm, carriage);
}
