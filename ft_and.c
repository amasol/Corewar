
#include "corewar.h"

extern const t_operations g_operations[16];

void		ft_and(t_vm *vm, t_carriage *carriage)
{
	ft_printf("\n\n\n\n\n\n");
	(void)vm;
	unsigned int pos;
	unsigned int num_reg[4];


	// ft_printf("arg_test ->[%d]\n",carriage->arg_type[0]);
	// ft_printf("arg_test ->[%d]\n",carriage->arg_type[1]);
	// ft_printf("arg_test ->[%d]\n",carriage->arg_type[2]);


	pos = carriage->position;
	num_reg[1] = (unsigned char)get_arg_from_map(vm->map, pos + 1, 1);
	num_reg[2] = (unsigned char)get_arg_from_map(vm->map, pos + 2, 1);
	num_reg[3] = (unsigned char)get_arg_from_map(vm->map, pos + 3, 1);
	// printf("test_num_teg ->[%d]\n", num_reg[1]);
	// printf("test_num_teg ->[%d]\n", num_reg[2]);
	// printf("test_num_teg ->[%d]\n", num_reg[3]);

	carriage->register_id[num_reg[3]] = carriage->register_id[num_reg[1]] & carriage->register_id[num_reg[2]];
	if (carriage->register_id[num_reg[3]] == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	printf("test_num_teg ->[%d]\n", carriage->register_id[num_reg[3]]);	


	ft_printf("\n\n\n\n\n\n");
}


// посмотреть уточнение за carry в таблице 

// достать три аргумента 
// |T_REG / T_DIR / T_IND 	|	T_REG / T_DIR / T_IND   |	T_REG

/*
Выполняет операцию «побитовое И» для значений первых двух аргументов 
и записывает полученный результат в регистр, переданный 
в качестве третьего аргумента.

Если записанный результат был равен нулю, 
то значение carry нужно установить равным 1. 
Если результат был не нулевой, то — равным 0.
*/

