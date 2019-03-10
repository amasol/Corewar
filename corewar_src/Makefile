# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 11:55:49 by bdomansk          #+#    #+#              #
#    Updated: 2018/04/23 11:55:51 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar
LIB = ../libft/libft.a
LIBDIR = ../libft
FLAGS = -Wall -Wextra -Werror 
COREWAR_SRC = main.c init_info.c put_manual.c parse_arguments.c reverse.c \
	print_winner.c is_natural.c check_bot.c error.c fill_map.c draw_map.c \
	new_carriage.c visualization_init.c check_key.c define_bots_id.c  \
	draw_info_table.c npause.c introducing_contestants.c sdl_mixer_init.c \
	print_map.c close_visulization.c perform_carriages.c check_carriages.c \
	ft_live.c operations.c ft_zjmp.c get_arg_from_map.c check_code_type.c \
	check_registers.c get_size_by_type.c move_carriage.c get_arg_by_type.c \
	ft_and.c ft_add.c get_arg_position.c draw_period.c ft_sub.c ft_ld.c \
	ft_or.c ft_xor.c ft_st.c rewrite_map.c ft_ldi.c ft_sti.c ft_fork.c \
	copy_carriage_data.c ft_lfork.c ft_lld.c ft_lldi.c ft_aff.c 
COREWAR_OBJ = $(COREWAR_SRC:.c=.o)
COREWAR_HEADER = ../includes/corewar.h ../includes/op_corewar.h
HEADER = -I ../includes
HEADER += -I ../frameworks/SDL2.framework/Headers/
HEADER += -I ../frameworks/SDL2_mixer.framework/Headers/ -F ../frameworks
FRAMEWORKS = -framework SDL2
FRAMEWORKS += -F  ../frameworks
FRAMEWORKS += -framework SDL2_mixer 
FRAMEWORKS += -rpath frameworks
DEL = /bin/rm -f

.PHONY : all clean n fclean re 

all : $(NAME)

$(NAME) : $(COREWAR_OBJ) $(LIB) 
	@echo "Compiling corewar"
	@gcc $(FLAGS) $(COREWAR_OBJ) -o $(NAME) -lncurses $(LIB) $(FRAMEWORKS)

$(COREWAR_OBJ): $(COREWAR_SRC) $(COREWAR_HEADER)
	@echo "Corewar objects creating"
	@gcc $(FLAGS) -c $(COREWAR_SRC) $(HEADER)


$(LIB) :
	@make -C $(LIBDIR)

clean:
	@$(DEL) $(COREWAR_OBJ)

n :
	@norminette $(COREWAR_SRC) 

fclean:
	@$(DEL) $(COREWAR_OBJ)
	@$(DEL) $(NAME)
	
re: fclean all