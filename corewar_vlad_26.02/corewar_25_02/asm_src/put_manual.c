/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_manual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:02:21 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/08 16:02:24 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	put_manual(t_asm *info)
{
	info->flags->h = 1;
	if (info->error_reason)
		error(info);
	if (info->flags->c)
		ft_printf("%s", AQUAMARINE);
	ft_printf("usage:	./asm [-hmlcind] champion[.s or .cor]\n\
	-h see the usage\n\
	-m turn on musical accompaniment\n\
	-l show leaks\n\
	-c enable colors\n\
	-i a new file is created in the current directory\n\
	-n show the number of line where the error occurred\n\
	-d disassembler\n");
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (info->flags->l)
		system("leaks asm");
	exit(0);
}
