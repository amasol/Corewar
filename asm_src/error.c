/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:14:23 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/08 16:14:26 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_reason(t_asm *info, char *reason)
{
	info->error_reason = reason;
	error(info);
}

void	error(t_asm *info)
{
	if (info->flags->m)
		system("afplay music/fail-trombone.mp3&");
	if (info->flags->c)
		ft_printf("%s", RED);
	ft_printf("ERROR: %s.\n", info->error_reason);
	if (info->flags->n && !info->flags->d)
		ft_printf("Error occurred at line number %d.\n", info->num_line);
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (!info->flags->h)
	{
		if (info->flags->l)
			system("leaks asm");
		exit(1);
	}
}
