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

typedef unsigned char	t_arr __attribute__((vector_size(sizeof(unsigned char) * 3)));


//# include <math.h>

//# define BUFF_S 10000

// структура по которой мы будем опеределять нашу функцию
typedef struct		s_op
{
}					t_op;


/*
** Validation
 */
typedef struct		s_val
{
//	int						id;
	unsigned char 			m_header[4];
	unsigned char 			bot_name[PROG_NAME_LENGTH];
	unsigned char 			n_null[4];
	unsigned char 			b_size[4];
	unsigned char 			b_comment[2048];
	unsigned char 			n_null_two[4];
	size_t					b_size_int;
	unsigned char 			*executable_code;
	int						fd;
	struct	s_val			*next;
}					t_val;

typedef struct		c_carriage
{
	unsigned char	register_id[16];
	int				position;
	int				carry;
	int				player_id;			// номер игрока который его породил.
	int				alive;				// живой или неи 0 || 1.
	int				execution_team;		// команду которую он исполняет.
	int				number_cycle;					// кол-во циклов, сколько ему осталось ждать до исполнения команды.
}					t_carriage;


int					main(void);
//int					main(int argc, char **argv);

t_val				*s_file();

void				processing_function(t_val *bot);


/*
** Error validation
 */
void				error(void);



size_t				shift_bit(unsigned char tmp, unsigned char tmp1);

/*
** Virtual machine
 */
void				ft_sti(unsigned char *codage);
t_arr				get_cod(char c);




#endif