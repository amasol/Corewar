
#include "corewar.h"

extern const t_operations g_operations[16];

void		ft_add_cr(t_vm *vm, t_carriage *carriage)
{

	unsigned int num_reg[4];
	unsigned int pos;

	pos = carriage->position;
	num_reg[1]= (unsigned char)get_arg_from_map(vm->map, pos + 1, 1);
	num_reg[2] = (unsigned char)get_arg_from_map(vm->map, pos + 2, 1);
	num_reg[3] = (unsigned char)get_arg_from_map(vm->map, pos + 3, 1);
	carriage->register_id[num_reg[3]] = carriage->register_id[num_reg[1]] + carriage->register_id[num_reg[2]];
	if (carriage->register_id[num_reg[3]] == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	if (!vm->flags->v && vm->flags->ops)
		ft_printf("P %4d | add r%u r%u r%u\n", carriage->id, num_reg[1], num_reg[2], num_reg[3]);
}

/*"Результат (первый плюс второй аргумент) записывается в третий.
В зависимости от того, что записали в третий меняем carry.
Если записали 0 меняем carry на 1, если не 0 меняем на 0."*/

