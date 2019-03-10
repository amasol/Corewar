/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_carriage_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:44:12 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/09 16:44:13 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	copy_carriage_data(t_carriage *dst, t_carriage *src)
{
	int	i;

	i = 1;
	while (i < REG_NUMBER)
	{
		dst->registers[i] = src->registers[i];
		i++;
	}
	dst->arg_type[0] = src->arg_type[0];
	dst->arg_type[1] = src->arg_type[2];
	dst->arg_type[2] = src->arg_type[2];
	dst->carry = src->carry;
	dst->cycle_last_live = src->cycle_last_live;
	dst->alive = src->alive;
}
