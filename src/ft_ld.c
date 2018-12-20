/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:05:17 by amasol            #+#    #+#             */
/*   Updated: 2018/12/20 18:05:19 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void				ft_ld(unsigned char *codage, t_carriage *carriage)
{
	t_arr	test2;
	int		i;

	i = 0;
	test2 = get_cod(codage[i]);

	printf("%d\n", test2[0]);
	printf("%d\n", test2[1]);
	printf("%d\n", test2[2]);
}
