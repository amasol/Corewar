/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:51:17 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/05 16:51:19 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_arg_position(t_carriage *carriage, int index)
{
	int	position;
	int i;

	i = 0;
	position = carriage->position + 1;
	while (i < index)
	{
		position = position + get_size_by_type(carriage, i);
		i++;
	}
	position = position % MEM_SIZE;
	return (position);
}
