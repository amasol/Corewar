/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:57:18 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/08 13:57:21 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	bonuses(t_asm *info)
{
	if (info->flags->c)
		ft_printf("%s", GREEN);
	ft_printf("Writing output program to %s\n", info->new_file_name);
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (info->flags->l)
		system("leaks asm");
	if (info->flags->m)
		system("afplay music/Winning.mp3&");
}
