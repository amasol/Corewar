/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:40:08 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/07 20:40:11 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	rewrite_map(t_vm *vm, t_carriage *carriage, int value, int address)
{
	int	position;
	int	size;
	int	temp;

	position = (carriage->position - 1 + address) % MEM_SIZE;
	size = 4;
	while (size)
	{
		size--;
		temp = value >> (size * 8);
		vm->map[position % MEM_SIZE].cell = (unsigned char)temp;
		vm->map[position % MEM_SIZE].color = carriage->parent->id;
		vm->map[position % MEM_SIZE].temp_color = carriage->parent->id + 40;
		vm->map[position % MEM_SIZE].cycles = 50;
		position++;
	}
}
