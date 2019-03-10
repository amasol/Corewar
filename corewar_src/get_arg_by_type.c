/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:42:18 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/05 12:42:20 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern const t_operations g_operations[16];

static int	get_arg_type_reg(t_map *map, t_carriage *carriage, int position)
{
	unsigned char	register_id;

	register_id = (unsigned char)get_arg_from_map(map, position, 1);
	return (carriage->registers[register_id]);
}

static int	get_arg_type_dir(t_map *map, t_carriage *carriage, int position)
{
	int	value;
	int	size;

	size = SIZE_DIR(carriage->opcode);
	if (size == 2)
		value = (short)get_arg_from_map(map, position, 2);
	else
		value = (int)get_arg_from_map(map, position, 4);
	return (value);
}

static int	get_arg_type_ind(t_map *map, t_carriage *carriage, int position)
{
	int	value;
	int	address;

	address = (short)get_arg_from_map(map, position, IND_SIZE);
	if (carriage->opcode != 13)
		address = address % IDX_MOD;
	value = (int)get_arg_from_map(map, carriage->position + address - 1, 4);
	return (value);
}

int			get_arg_by_type(t_vm *vm, t_carriage *carriage, int index)
{
	int	type;
	int position;

	type = carriage->arg_type[index];
	position = get_arg_position(carriage, index);
	if (type == T_REG)
		return (get_arg_type_reg(vm->map, carriage, position));
	if (type == T_DIR)
		return (get_arg_type_dir(vm->map, carriage, position));
	else
		return (get_arg_type_ind(vm->map, carriage, position));
}
