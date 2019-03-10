/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:10:07 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/09 20:10:08 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_aff(t_vm *vm, t_carriage *carriage)
{
	int	reg_id;
	int	position;
	int	value;

	position = carriage->position + 1;
	reg_id = (unsigned char)get_arg_from_map(vm->map, position, 1);
	value = carriage->registers[reg_id];
	if (!vm->flags->v)
		ft_printf("Aff: %c\n", (char)value);
	move_carriage(vm, carriage);
}
