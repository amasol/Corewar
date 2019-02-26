
#include "corewar.h"

t_arr				get_cod(char c)
{
	int 	i;
	t_arr	arr;
	int 	num;

	i = 0;
	while (i < 3)
	{
		num = c >> (6 - 2 * i) & 3;
		if (num == REG_CODE)
			arr[i] = T_REG;
		else if (num == DIR_CODE)
			arr[i] = T_DIR;
		else if (num == IND_CODE)
			arr[i] = T_IND;
		++i;
	}
	return (arr);
}