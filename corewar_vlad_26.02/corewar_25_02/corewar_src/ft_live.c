/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:10:59 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/25 17:11:00 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_vm *vm, t_carriage *carriage)
{
	ft_printf("Live.On map %0.2x\n", vm->map[carriage->position].cell);
}
