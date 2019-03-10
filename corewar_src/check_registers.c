/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_registers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:52:19 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/02 18:52:20 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern const t_operations g_operations[16];

static int	check_register_value(t_map *map, int position)
{
	unsigned char type;

	type = (unsigned char)get_arg_from_map(map, position, 1);
	if (type < 1 || type > 16)
		return (0);
	return (1);
}

int			check_registers(t_vm *vm, t_carriage *carriage)
{
	int	i;
	int	new_position;

	i = 0;
	new_position = carriage->position + 1;
	while (i < carriage->number_of_arguments)
	{
		if (carriage->arg_type[i] == T_REG)
			if (!check_register_value(vm->map, new_position % MEM_SIZE))
				return (0);
		new_position = new_position + get_size_by_type(carriage, i);
		i++;
	}
	return (1);
}
