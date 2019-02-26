
#include "corewar.h"
/*
void			ft_set_num(t_map *map, int pos, int size, unsigned int num)
{
	int i;

	i = 0;
	while (i < size)
	{
		map[(pos + i) % MEM_SIZE] = (num >> ((size - 1 - i) * 8)) & 0xFF;
		i++;
	}	
}
*/
unsigned int	ft_get_num(t_map *map, int pos, int size)
{
	unsigned int res;

	res = 0;
	// printf("\n",);
	while (size > 0)
	{
		--size;
		res |= (unsigned int)(map[pos % MEM_SIZE].cell) << (size * 8);
		pos++;
	}
	return (res);
}
