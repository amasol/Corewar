# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 16:09:40 by bdomansk          #+#    #+#              #
#    Updated: 2018/04/24 14:29:47 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h 
FLAGS = -Wall -Wextra -Werror
SRC = ft_putchar.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strstr.c ft_strrchr.c\
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memalloc.c \
	  ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_whitespaces.c ft_itoa_base.c  \
	  ft_unicode_check.c ft_bubble_sort.c \
	  ft_add.c get_next_line.c ft_put_bigs.c ft_uitoa.c ft_putoux.c ft_putd.c \
	  ft_puts.c ft_putc.c ft_select_type.c ft_find_specifiers.c ft_printf.c
OBJ = $(SRC:.c=.o)
NORM = norminette

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Libft.a creating"
	@ar rc $(NAME) $(OBJ)
$(OBJ): $(SRC)
	@echo "Libft objects creating"
	@gcc $(FLAGS) -c -I $(HEADER) $(SRC)

n : 
	@$(NORM) $(SRC) $(HEADER) ft_printf.h
clean:
	@/bin/rm -f $(OBJ)
	@echo "Clean objects"
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "General clean"
re: fclean all

