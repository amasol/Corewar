#include "corewar.h"

void		ft_or(t_vm *vm, t_carriage *carriage)
{
	unsigned int	pos;
	unsigned int	reg_pos;
	int 			value[2];

	value[0] = get_arg_by_type(vm, carriage, 0);
	value[1] = get_arg_by_type(vm, carriage, 1);
	pos = get_arg_position(carriage, 2);
	reg_pos = (unsigned char)get_arg_from_map(vm->map, pos, 1);
	carriage->registers[reg_pos] = value[0] | value[1];
	carriage->carry = (carriage->registers[reg_pos] == 0) ? 1 : 0;
	if (!vm->flags->v && vm->flags->ops)
		ft_printf("P %4d | or %d %d r%d\n",
		carriage->id, value[0], value[1], reg_pos);
	move_carriage(carriage);
}

/*
Выполняет операцию «побитовое |» для значений первых двух аргументов 
и записывает полученный результат в регистр, переданный 
в качестве третьего аргумента.

Если записанный результат был равен нулю, 
то значение carry нужно установить равным 1. 
Если результат был не нулевой, то — равным 0.
*/

