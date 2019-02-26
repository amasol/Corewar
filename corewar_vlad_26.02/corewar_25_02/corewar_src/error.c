/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:35:21 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/12 11:35:22 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_reason(t_vm *info, char *reason)
{
	info->error_reason = reason;
	error(info);
}

void	error(t_vm *info)
{
	if (info->flags->m)
		system("afplay music/fail-trombone.mp3&");
	if (info->flags->c)
		ft_printf("%s", RED);
	ft_printf("ERROR: %s.\n", info->error_reason);
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (!info->flags->h)
	{
		if (info->flags->l)
			system("leaks corewar");
		exit(1);
	}
}
