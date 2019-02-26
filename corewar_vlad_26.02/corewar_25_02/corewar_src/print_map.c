/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 12:03:59 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/24 12:04:01 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** если будет флаг dump32 нужно будет сделать i % 32 и другой принтф
*/

static void	print_colour_map(t_vm *vm)
{
	int i;
	int	bytes;

	i = 0;
	bytes = vm->flags->dump_bytes;
	while (i < MEM_SIZE)
	{
		if (i && (i % bytes) == 0)
			ft_printf("\n");
		if (i % bytes == 0)
			ft_printf("\033[90m0x%04x :\033[0m", i);
		if (vm->map[i].color == 10)
			ft_printf("\033[90m %0.2x\033[0m", vm->map[i].cell);
		else if (vm->map[i].color == 1)
			ft_printf("%s %0.2x%s", YELLOW, vm->map[i].cell, DEF);
		else if (vm->map[i].color == 2)
			ft_printf("%s %0.2x%s", GREEN, vm->map[i].cell, DEF);
		else if (vm->map[i].color == 3)
			ft_printf("%s %0.2x%s", BLUE, vm->map[i].cell, DEF);
		else if (vm->map[i].color == 4)
			ft_printf("%s %0.2x%s", RED, vm->map[i].cell, DEF);
		i++;
	}
	printf("\n");
}

void		print_map(t_vm *vm)
{
	int i;
	int	bytes;

	i = 0;
	bytes = vm->flags->dump_bytes;
	if (vm->flags->c)
		print_colour_map(vm);
	else
	{
		while (i < MEM_SIZE)
		{
			if (i && (i % bytes) == 0)
				ft_printf("\n");
			if (i % bytes == 0)
				ft_printf("0x%04x :", i);
			ft_printf(" %0.2x", vm->map[i].cell);
			i++;
		}
		ft_printf("\n");
	}
}
