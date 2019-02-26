# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:48:14 by bdomansk          #+#    #+#              #
#    Updated: 2017/12/17 18:51:01 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
COREWAR = corewar
LIB = libft/libft.a
LIBDIR = libft
ASMDIR = asm_src
COREWARDIR = corewar_src
INCLUDES = includes/
FLAGS = -Wall -Wextra -Werror
DEL = /bin/rm -f

.PHONY : all clean n fclean re vm asm

all : asm vm

asm : 
	@make -C $(ASMDIR)

vm :
	@make -C $(COREWARDIR)

clean:
	@make -C $(ASMDIR)/ clean
	@make -C $(COREWARDIR)/ clean
	@make -C $(LIBDIR)/ clean

n :
	@norminette $(INCLUDES)
	@make -C $(LIBDIR)/ n
	@make -C $(ASMDIR)/ n
	@make -C $(COREWARDIR)/ n

fclean:
	@make -C $(LIBDIR)/ fclean
	@make -C $(ASMDIR)/ fclean
	@make -C $(COREWARDIR)/ fclean

re: fclean all

