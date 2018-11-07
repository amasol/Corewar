/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:39:57 by amasol            #+#    #+#             */
/*   Updated: 2018/10/31 11:39:59 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "op.h"

# include <stdio.h>
//# include <math.h>

//# define BUFF_S 10000

/*
** Валидация
 */
typedef struct		s_val
{
	unsigned char 			m_header[4];
	unsigned char 			bot_name[PROG_NAME_LENGTH];
	unsigned char 			n_null[4];
	unsigned char 			b_size[4];
	unsigned char 			b_comment[2048];
	unsigned char 			n_null_two[4];
	int						b_size_int;
//	unsigned char 			executable_code[//перевести в 10- код, тут будет наж b_size];
	int				fd;
}					t_val;





int					main(void);
void				error(void);
void				s_file();
int					ft_atoi_base(unsigned char *nb, int base);

#endif