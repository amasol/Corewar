/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:40:05 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/01 12:40:07 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Если для конкретной операции нужен код типов аргументов, то находим его
** и записываем в каретку, проверяем подходит ли полученный код к операции.
** Проверяем все существующее регистры (T_REG) на валидность.
** Eсли где-то произошла ошибка возвращаем 0, иначе в конце вернем 1.
*/

extern const t_operations g_operations[16];

static int	find_type(unsigned char code)
{
	if (code == REG_CODE)
		return (T_REG);
	else if (code == DIR_CODE)
		return (T_DIR);
	else if (code == IND_CODE)
		return (T_IND);
	return (0);
}

static void	read_code_type(t_vm *vm, t_carriage *carriage)
{
	unsigned char	code_type;

	code_type = get_arg_from_map(vm->map, carriage->position, 1);
	carriage->arg_type[0] = find_type((code_type >> 6) & 3);
	if (carriage->number_of_arguments > 1)
		carriage->arg_type[1] = find_type((code_type >> 4) & 3);
	if (carriage->number_of_arguments > 2)
		carriage->arg_type[2] = find_type((code_type >> 2) & 3);
}

static int	check_similarity(t_carriage *carriage)
{
	int	i;
	int	desired_type;

	i = 0;
	while (i < carriage->number_of_arguments)
	{
		desired_type = TYPE_ARG(carriage->opcode, i);
		if (!carriage->arg_type[i])
			return (0);
		if ((desired_type | carriage->arg_type[i]) != desired_type)
			return (0);
		i++;
	}
	return (1);
}

static void	fill_arguments(t_carriage *carriage)
{
	int	i;

	i = 0;
	while (i < carriage->number_of_arguments)
	{
		carriage->arg_type[i] = TYPE_ARG(carriage->opcode, i);
		i++;
	}
}

int			check_code_type(t_vm *vm, t_carriage *carriage)
{
	if (CODE_TYPE(carriage->opcode))
	{
		carriage->position = (carriage->position + 1) % MEM_SIZE;
		read_code_type(vm, carriage);
		if (!check_similarity(carriage))
			return (0);
	}
	else
		fill_arguments(carriage);
	return (check_registers(vm, carriage));
}
