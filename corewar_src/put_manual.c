/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_manual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:59:44 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/12 10:59:46 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	put_manual(t_vm *info)
{
	char	*line;
	int		fd;

	info->flags->h = 1;
	if (info->error_reason)
		error(info);
	if (info->flags->c)
		ft_printf("%s", AQUAMARINE);
	line = NULL;
	fd = open("manual_corewar", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (info->flags->l)
		system("leaks corewar");
	exit(0);
}
