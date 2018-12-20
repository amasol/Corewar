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
/*
typedef struct		operations
{
//	void (*func)(void);
	void (*ft_sti)(&codage, &carriage);
}					operations;
*/

//# include <math.h>

//# define BUFF_S 10000

// структура по которой мы будем опеределять нашу функцию
//typedef struct		s_op
//{
//}					t_op;

/*
** Validation
 */

typedef struct		s_val
{
//	int						id;
	unsigned char 			m_header[4];
	unsigned char 			b_comment[2048];
	unsigned char 			bot_name[PROG_NAME_LENGTH];
	unsigned char 			*executable_code;
	unsigned char 			b_size[4];
	size_t					b_size_int;
	int						fd;
}					t_val;

/*
** Каретка
 */
typedef struct		c_carriage
{
	unsigned int		register_id[REG_NUMBER];
	int					position;
	int					carry;
	int					player_id;			// номер игрока который его породил.
	int					alive;				// живой или нет 0 || 1.
	int					execution_team;		// команду которую он исполняет.
	int					number_cycle;					// кол-во циклов, сколько ему осталось ждать до исполнения команды.
	struct t_carriage	*next;
	struct t_carriage	*last;
}					t_carriage;


//int					main(void);
int					main(int argc, char **argv);

t_val				s_file(char *bot);

void				parsingflag(char *flag);
int					processing_function(t_val *bot, t_carriage *carriage);
//void				search_func(t_carriage *carriage);


/*
** Error validation
 */
void				error(char *str);



//unsigned			shift_bit(unsigned char *buff);  // вытаскивание наших аргументов
size_t				shift_bit(unsigned char tmp, unsigned char tmp2);

/*
** Virtual machine
 */
void				ft_live(unsigned char *codage, t_carriage *carriage);
void				ft_ld(unsigned char *codage, t_carriage *carriage);

int				ft_sti(unsigned char *codage, t_carriage *carriage);

void				ft_and(unsigned char *codage, t_carriage *carriage);
void				ft_xor(unsigned char *codage, t_carriage *carriage);

t_arr				get_cod(char c);




#endif