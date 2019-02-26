
#include "corewar.h"

void		ft_zjmp(t_vm *vm, t_carriage *carriage)
{
	if (carriage->carry == 1)
		carriage->position += (int)ft_get_num(vm->map, carriage->position + 1, 2) % IDX_MOD;
}
