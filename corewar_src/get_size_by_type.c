/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_by_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:09:22 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/03 15:09:24 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern const t_operations g_operations[16];

int	get_size_by_type(t_carriage *carriage, int i)
{
	if (carriage->arg_type[i] == T_DIR)
		return (SIZE_DIR(carriage->opcode));
	if (carriage->arg_type[i] == T_IND)
		return (IND_SIZE);
	if (carriage->arg_type[i] == T_REG)
		return (1);
	return (0);
}
