# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 15:30:37 by amasol            #+#    #+#              #
#    Updated: 2018/03/22 19:32:08 by amasol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
flg = -Wall -Wextra -Werror
SRS = ft_fact.c ft_space.c ft_score.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_memchr.c ft_toupper.c ft_atoi.c ft_strcat.c ft_strncat.c ft_strcpy.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isprint.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strncpy.c ft_memalloc.c ft_strstr.c ft_tolower.c ft_strrchr.c ft_isdigit.c ft_isascii.c ft_memcpy.c ft_strnstr.c ft_strnew.c ft_memdel.c ft_putchar.c ft_putstr.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c get_next_line.c ft_above_zero.c
OBJ = $(SRS:.c=.o)
HEADER =./libft.h get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
clean:
	@ rm -rf $(OBJ)
.c.o:
	@ $(CC) $(flg) -c $< -o $@
fclean: clean
	@ rm -rf $(NAME) $(OBJ)
re: fclean all
