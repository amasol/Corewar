/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:30:26 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/09 17:30:29 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			create_file(t_asm *info)
{
	char *error;
	char *s;

	info->new_fd = open(info->new_file_name, O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (info->new_fd == -1)
	{
		s = "Can't create file with name : ";
		error = ft_strjoin(s, info->new_file_name);
		error_reason(info, error);
	}
}
