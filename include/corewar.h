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
# include <ncurses.h>

#define UC unsigned char
#define	FNUM 16


typedef UC				t_arr __attribute__((vector_size(sizeof(UC) * 3)));
typedef struct			s_carriage t_carriage;
typedef struct			s_bot t_bot;
typedef	struct			s_map t_map;



/*
** Function Dispatcher
*/

typedef struct			s_func
{
	int					command;
	void				(*fptr)(UC *, t_carriage *);
}						t_func;
extern t_func			g_funclist[FNUM];


struct					s_map
{
	UC					cell;
	int					color;
};

t_map					g_map[MEM_SIZE];


struct					s_bot
{
	int					id;
	int					position;
	unsigned char 		m_header[4];
	unsigned char 		b_comment[2048];
	unsigned char 		bot_name[PROG_NAME_LENGTH];
	unsigned char 		*exec_code;
	unsigned char 		b_size[4];
	size_t				size;
};

/*
** Каретка
 */

struct					s_carriage
{
	unsigned int		register_id[REG_NUMBER];
	int					position;
	int					carry;
	int					player_id;			// номер игрока который его породил.
	int					alive;				// живой или нет 0 || 1.
	int					exec_command;		// команду которую он исполняет.
	int					number_cycle;		// кол-во циклов, сколько ему осталось ждать до исполнения команды.
	t_carriage			*next;
};

//					параметры игроков
struct					s_game_parameter
{
	int					live_bot; //игрок который последний раз сказал что он жив
};


t_bot				read_file(char *bot, int bot_id);

//void				parsingflag(char *flag);
//void				processing_function(t_val *bot, t_carriage *carriage);
//void				search_func(t_carriage *carriage);


/*
** Error validation
 */
void				ft_error(char *str);



size_t          	bot_size(unsigned char size []);

/*
** Virtual machine
 */

void		print_map(t_carriage *carriage, int delay);
void		init_colors();
void		npause(void);
void	visualization(t_carriage *carriage);


/*
** Functions
 */
void	ft_add(unsigned char *codage, t_carriage *carriage);
void	ft_aff(unsigned char *codage, t_carriage *carriage);
void	ft_and(unsigned char *codage, t_carriage *carriage);
void	ft_fork(unsigned char *codage, t_carriage *carriage);
void	ft_ld(unsigned char *codage, t_carriage *carriage);
void	ft_ldi(unsigned char *codage, t_carriage *carriage);
void	ft_lfork(unsigned char *codage, t_carriage *carriage);
void	ft_live(unsigned char *codage, t_carriage *carriage);
void	ft_lld(unsigned char *codage, t_carriage *carriage);
void	ft_lldi(unsigned char *codage, t_carriage *carriage);
void	ft_or(unsigned char *codage, t_carriage *carriage);
void	ft_st(unsigned char *codage, t_carriage *carriage);
void	ft_sti(unsigned char *map, t_carriage *carriage);
void	ft_sub(unsigned char *codage, t_carriage *carriage);
void	ft_xor(unsigned char *codage, t_carriage *carriage);
void	ft_zjmp(unsigned char *codage, t_carriage *carriage);




t_arr				get_cod(char c);




#endif