
#include "corewar.h"


void			ft_sti(t_vm *vm, t_carriage *carriage)
{
	unsigned int	pos;
	int				value[3];
	int				value_arg;
	int				new_pos;


	pos = get_arg_position(carriage, 0);
	value_arg = (unsigned char)get_arg_from_map(vm->map, pos, 0);
	value[1] = get_arg_by_type(vm, carriage, 1);
	value[2] = get_arg_by_type(vm, carriage, 2);
	new_pos = (value[1] + value[2] % IDX_MOD) + carriage->position - 1;
	carriage->registers[value_arg] = (int)get_arg_from_map(vm->map, new_pos, 4);
}

// В ПЕРВОМ СЛУЧАЕ НИЧЕГО НЕ СКАЗАНО ЗА КОЛИЧЕСТВО БАЙТ 
/* "Значение T_REG (первый аргумент) записывается в ячейку, по адресу 
(текущая позиция PC + ((второй аргумент плюс третий аргумент) % IDX_MOD))

- Если второй аргумент T_IND - то ясное дело, что вместо второго аргумента,
в уровнение подставляются те 4 байта, которые мы берём из ячейки (T_IND % IDX_MOD)."*/
