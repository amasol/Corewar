
#include "corewar.h"

void		ft_zjmp(t_vm *vm, t_carriage *carriage)
{
	vm = NULL;
	printf("TEST ft_zjmp\n");
	if (carriage->carry == 1)
	{
		printf("carry test 1-> %d\n", carriage->position);
		// carr->position += ft_get_num(vm->map, carr->position, 2) % IDX_MOD;
		carriage->position += 3;
		printf("carry test 2 -> %d\n", carriage->position);
	}
}
